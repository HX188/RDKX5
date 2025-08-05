import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    tts_dir = get_package_share_directory('tts')
    tts_launch_dir = os.path.join(tts_dir, 'launch')
    tts_config = os.path.join(tts_dir, 'config', 'tts_params.yaml')
    resource_param = {"source_path": tts_dir}


    tts_make = Node(
        package="tts",
        executable="tts_node",
        output='screen',
        parameters=[resource_param,
            tts_config]                     
    )

    rdk_ai_gateway_service = Node(
        package="rdk_ai_gateway",
        executable="service",
        output='screen',  #四个可选项 
        parameters=['/home/sunrise/AI/AI_whole/src/rdk_ai_gateway_ros/rdk_ai_gateway/config/param.yaml']
    )

    rdk_ai_gateway_client = Node(
        package="rdk_ai_gateway",
        executable="client",
        output='screen',  #四个可选项 
        parameters=['/home/sunrise/AI/AI_whole/src/rdk_ai_gateway_ros/rdk_ai_gateway/config/param.yaml']
    )

    wheeltec_mic = Node(
        package="wheeltec_mic_ros2",
        executable="wheeltec_mic",
        output='screen',
        parameters=[{"usart_port_name": "/dev/wheeltec_mic",
                    "serial_baud_rate": 115200}]
    )

    wheeltec_aiui = Node(
        package="wheeltec_aiui",
        executable="wheeltec_aiui",
        output='screen',
    )

    ld = LaunchDescription()

    ld.add_action(tts_make)
    ld.add_action(rdk_ai_gateway_service)
    ld.add_action(rdk_ai_gateway_client)
    ld.add_action(wheeltec_mic)
    ld.add_action(wheeltec_aiui)
    
    return ld