from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_end',
            executable='main',
            name='minimal_publisher',
            output='screen'
        ),
        Node(
            package='ros2_end',
            executable='serial_sender_node',
            name='serial_sender_node',
            output='screen'
        ),
    ])