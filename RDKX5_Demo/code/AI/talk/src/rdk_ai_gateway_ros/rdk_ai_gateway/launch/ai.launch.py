# 导入库
from launch import LaunchDescription
from launch_ros.actions import Node
import os

# param_file = os.path.join(
#         os.path.dirname(__file__), '..', 'config', 'param.yaml'
#     )
# param_file = os.path.abspath(param_file)

def generate_launch_description():
    # 创建Actions.Node对象li_node，标明李四所在位置
    rdk_ai_gateway = Node(
        package="rdk_ai_gateway",
        executable="service",
        output='screen',  #四个可选项 
        parameters=['/home/sunrise/AI/talk/src/rdk_ai_gateway_ros/rdk_ai_gateway/config/param.yaml']
        )

    return LaunchDescription([rdk_ai_gateway])