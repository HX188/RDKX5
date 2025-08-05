#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <iostream>

class SerialSenderNode : public rclcpp::Node {
public:
    SerialSenderNode() : Node("serial_sender_node") {
        // 串口初始化
        serial_fd_ = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_SYNC);
        if (serial_fd_ < 0) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open serial port.");
            return;
        }

        struct termios tty;
        if (tcgetattr(serial_fd_, &tty) != 0) {
            RCLCPP_ERROR(this->get_logger(), "Failed to get serial attributes.");
            return;
        }

        cfsetospeed(&tty, B115200);
        cfsetispeed(&tty, B115200);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        tty.c_iflag &= ~IGNBRK;                         // disable break processing
        tty.c_lflag = 0;                                // no signaling chars, no echo
        tty.c_oflag = 0;                                // no remapping, no delays
        tty.c_cc[VMIN]  = 1;                            // read doesn't block
        tty.c_cc[VTIME] = 5;                            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // shut off xon/xoff ctrl
        tty.c_cflag |= (CLOCAL | CREAD);                // ignore modem controls
        tty.c_cflag &= ~(PARENB | PARODD);              // no parity
        tty.c_cflag &= ~CSTOPB;                         // 1 stop bit
        tty.c_cflag &= ~CRTSCTS;                        // no hardware flow control

        if (tcsetattr(serial_fd_, TCSANOW, &tty) != 0) {
            RCLCPP_ERROR(this->get_logger(), "Failed to set serial attributes.");
            return;
        }

        // 创建订阅者
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic", 10,
            std::bind(&SerialSenderNode::topic_callback, this, std::placeholders::_1)
        );

        // 新增：订阅 cmd_vel_string 话题
        cmd_vel_string_subscription_ = this->create_subscription<std_msgs::msg::String>(
            "cmd_vel_string", 10,
            std::bind(&SerialSenderNode::topic_callback, this, std::placeholders::_1)
        );

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(200),
            std::bind(&SerialSenderNode::timer_callback, this));

        RCLCPP_INFO(this->get_logger(), "SerialSenderNode initialized and subscribed to 'topic'");
    }

    ~SerialSenderNode() {
        if (serial_fd_ >= 0) {
            close(serial_fd_);
        }
    }

private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) {
        // std::string data = msg->data + "\n"; // 追加换行方便STM32识别
        // ssize_t bytes_written = write(serial_fd_, data.c_str(), data.length());
        // if (bytes_written < 0) {
        //     RCLCPP_ERROR(this->get_logger(), "Failed to write to serial port.");
        // } else {
        //     RCLCPP_INFO(this->get_logger(), "Sent to STM32: '%s'", msg->data.c_str());
        // }

        latest_msg_ = msg->data;
    }

     void timer_callback() {
        if (!latest_msg_.empty()) {
            std::string data = latest_msg_ + "\n";
            ssize_t bytes_written = write(serial_fd_, data.c_str(), data.length());
            if (bytes_written < 0) {
                RCLCPP_ERROR(this->get_logger(), "Failed to write to serial port.");
            } else {
                RCLCPP_INFO(this->get_logger(), "Sent to STM32: '%s'", latest_msg_.c_str());
            }
            // 如果只想每条消息只发一次，可以发完后清空
            latest_msg_.clear();
        }
    }
    rclcpp::TimerBase::SharedPtr timer_;
    std::string latest_msg_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr cmd_vel_string_subscription_;
    int serial_fd_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SerialSenderNode>());
    rclcpp::shutdown();
    return 0;
}
