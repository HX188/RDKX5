import rclpy
from rclpy.node import Node
from rdk_ai_gateway_msg.srv import TextToText  # Adjust the import according to your service name
from std_msgs.msg import String

class InferClient(Node):

    def __init__(self):
        super().__init__('infer_client')
        self.client = self.create_client(TextToText, 'text_to_text')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.request = TextToText.Request()

        self.tts_text_pub = self.create_publisher(String, 'tts_text', 10)
        self.subscription = self.create_subscription(
        String,
        'chat_message',  # 话题名
        self.chat_message_callback,  # 回调函数
        10
        )

        # Declare parameters
        #self.declare_parameter('input_str', '晚上吃什么')
        self.declare_parameter('model', 'doubao-pro-128k')  # Default to 0, should be an integer

        # Retrieve parameters
        #self.input_str = self.get_parameter('input_str').get_parameter_value().string_value
        self.model = self.get_parameter('model').get_parameter_value().string_value


    def send_request(self, input_str):
        self.request.input = input_str
        self.request.model = self.model
        self.future = self.client.call_async(self.request)
        self.future.add_done_callback(self.handle_service_response)
        #rclpy.spin_until_future_complete(self, self.future)
        #return self.future.result()

    def handle_service_response(self, future):
        response = future.result()
        if response is not None:
            self.get_logger().info(f'Result: {response.output}')
            # 发布到 tts_text 话题
            msg = String()
            msg.data = str(response.output)
            self.tts_text_pub.publish(msg)
        else:
            self.get_logger().warn('服务端无响应或返回None')


    def chat_message_callback(self, msg):
        input_str = msg.data  # 获取到的话题内容
        # Send the request using parameters
        response = self.send_request(input_str)

        # self.get_logger().info(f'Result: {response.output}')

        



def main(args=None):
    rclpy.init(args=args)
    infer_client = InferClient()

    rclpy.spin(infer_client)  # 一直循环，自动处理所有回调
    
    

    infer_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


