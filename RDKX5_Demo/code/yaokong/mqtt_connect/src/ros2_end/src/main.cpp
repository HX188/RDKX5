#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "MQTTClient.h"
#include "mqtt_c.hpp"

using namespace std::chrono_literals;

bool containsChinese(const std::string& str) {
    for (size_t i = 0; i < str.size(); ) {
        unsigned char c = str[i];
        if (c >= 0xE4 && c <= 0xE9) {
            // 检查后面两个字节是否是UTF-8的多字节
            if (i + 2 < str.size()) {
                unsigned char c1 = str[i + 1];
                unsigned char c2 = str[i + 2];
                if ((c1 & 0xC0) == 0x80 && (c2 & 0xC0) == 0x80) {
                    return true;
                }
            }
            i += 3;
        } else if ((c & 0x80) == 0) {
            // 英文字符
            i += 1;
        } else if ((c & 0xE0) == 0xC0) {
            // 2字节UTF-8
            i += 2;
        } else if ((c & 0xF0) == 0xF0) {
            // 4字节UTF-8
            i += 4;
        } else {
            // 其他情况
            i += 1;
        }
    }
    return false;
}

class MinimalPublisher : public rclcpp::Node {
public:
    MinimalPublisher() : Node("minimal_publisher") {
        // 初始化ros发布的消息
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        tts_text_pub = this->create_publisher<std_msgs::msg::String>("tts_text", 10);

        // 初始化mqtt的消息及加载回调函数
        mqtt_ = new Mqtt_C("tcp://broker.emqx.io:1883", "c-client", "test", "test", "/wechat_ros/mqtt", 0, std::bind(&MinimalPublisher::getMqttMessage, 
                                                                                                                     this,
                                                                                                                     std::placeholders::_1,
                                                                                                                     std::placeholders::_2,
                                                                                                                     std::placeholders::_3,
                                                                                                                     std::placeholders::_4));
    }
    
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr tts_text_pub;
    
    Mqtt_C_Ptr mqtt_;

    // 定义mqtt的回调函数
    void getMqttMessage(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
        if (!message || !message->payload || !topicName) 
        {
        RCLCPP_ERROR(this->get_logger(), "MQTT回调收到空指针，终止处理");
        return;
        }
        auto* payload = message->payload;
        std::string payload_str((char*)payload, message->payloadlen);  // 用长度安全构造
        std::cout << "Received " << payload_str << " from " << topicName << " topic" << std::endl;
        //std::cout << "Received " << (char*)(payload) << " from " << topicName << " topic" << std::endl;

        // 发布mqtt消息
        //mqtt_->publish("/wechat_ros_return/mqtt", "ros2 to wechat");

        // 发布ros消息
        auto ros_message = std_msgs::msg::String();
        //ros_message.data = (char*)(payload);
        ros_message.data = payload_str;

        if (containsChinese(ros_message.data)) 
        {
            tts_text_pub->publish(ros_message);
            RCLCPP_INFO(this->get_logger(), "中文：: '%s'", ros_message.data.c_str());
        }
        else {
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", ros_message.data.c_str());
            publisher_->publish(ros_message);
        }
    
}
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
