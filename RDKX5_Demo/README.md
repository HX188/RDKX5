# RDKX5_Demo
* 本目录下的子文件夹code即主控RDK端的运行代码。
* code文件夹总共包含四个文件夹，分别是AI、down_detection、hand_gesture_recognize、yaokong。

# 功能介绍
* 我们的项目包含多个功能，下面将介绍各个功能的运行指令

# 1.手势控制
ros2 launch ros2_end yao_kong.launch.py # 在yangkong/目录下
ros2 launch hand_gesture_detection_develop hand_gesture_detection.launch.py # 在hand_gesture_recognize/目录下

# 2.语音对话
* ros2 launch wheeltec_aiui aiui_start.launch.py    # 在AI/AI_whole目录下

# 3.语音控制
* ros2 launch ros2_end yao_kong.launch.py   # 在yangkong/目录下
* ros2 launch wheeltec_mic_ros2 base.launch.py  # 在AI/sound/wheeltec_mic目录下
* ros2 launch wheeltec_mic_ros2 mic_init.launch.py  # 在AI/sound/wheeltec_mic目录下

# 4.人体跟随与摔倒检测
* ros2 launch ros2_end yao_kong.launch.py   # 在yangkong/目录下
* ros2 launch body_tracking_custom body_tracking_without_gesture    # 在down_detection/目录下
* ros2 run fall_detector_py fall_detector_node  # 在down_detection/目录下
* ros2 launch tts tts_make.launch.py    # 在AI/test_to_sound/目录下

# 5.遥控与远程播报
* ros2 launch ros2_end yao_kong.launch.py   # 在yangkong/目录下
* ros2 launch tts tts_make.launch.py    # 在AI/test_to_sound/目录下
