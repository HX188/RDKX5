import rclpy
from rclpy.node import Node
from rclpy.logging import get_logger
import time  # 新增：用于时间间隔判断

from ai_msgs.msg import PerceptionTargets # 导入感知消息类型
from std_msgs.msg import String  # 新增：导入String消息类型

import math # 用于数学计算

# 定义摔倒状态
class FallStatus:
    NORMAL = 0
    POSSIBLE_FALL = 1 # 疑似摔倒
    FALL_DETECTED = 2  # 确认摔倒

class FallDetectorNode(Node):

    def __init__(self):
        super().__init__('fall_detector_node') # 初始化节点名称

        # 声明参数 (可以根据需要添加更多，并通过launch文件或yaml文件配置)
        self.declare_parameter('aspect_ratio_threshold', 1.5) # 宽度/高度 > 1.5 视为可能摔倒 (侧躺)
        self.declare_parameter('angle_threshold_deg', 60.0) # 骨盆-颈部连线与垂直方向夹角 > 45度视为可能摔倒
        self.declare_parameter('consecutive_fall_frames_thr', 5) # 连续多少帧满足条件视为确认摔倒

        self.aspect_ratio_threshold = self.get_parameter('aspect_ratio_threshold').get_parameter_value().double_value
        self.angle_threshold_deg = self.get_parameter('angle_threshold_deg').get_parameter_value().double_value
        self.consecutive_fall_frames_thr = self.get_parameter('consecutive_fall_frames_thr').get_parameter_value().integer_value

        get_logger(self.get_name()).info(f"FallDetectorNode initialized with parameters: aspect_ratio_threshold={self.aspect_ratio_threshold}, angle_threshold_deg={self.angle_threshold_deg}, consecutive_fall_frames_thr={self.consecutive_fall_frames_thr}")


        # 创建订阅者，订阅 PerceptionTargets 话题
        # 请根据你的实际话题名称修改 '/ai_msgs/msg/PerceptionTargets'
        self.subscription = self.create_subscription(
            PerceptionTargets,
            '/hobot_mono2d_body_detection', # 替换成你的PerceptionTargets话题名称
            self.perception_targets_callback,
            10) # QoS history depth
        #self.awake_flag_pub = self.create_publisher("tts_text",10)
        self.tts_make_pub = self.create_publisher(String, '/tts_text', 10)  # 新增tts_make话题发布者
        #self.subscription # prevent unused variable warning

        # 保存每个目标的摔倒状态和连续计数
        self.target_fall_status = {} # {track_id: FallStatus}
        self.target_consecutive_fall_frames = {} # {track_id: count}

        # (可选) 创建发布者，用于发布摔倒检测结果
        # 你可能需要定义一个新的消息类型来发布摔倒信息
       # self.fall_event_publisher = self.create_publisher(FallEventMsg, '/fall_events', 10)

        self.last_tts_publish_time = 0  # 新增：记录上次tts_make发布时间

    def perception_targets_callback(self, msg):
        # get_logger(self.get_name()).info(f"Received PerceptionTargets message with {len(msg.targets)} targets")

        current_frame_fall_status = {} # 记录当前帧每个目标的摔倒状态

        # 遍历消息中的每个目标
        for target in msg.targets:
            # 只对类型为 person 的目标进行处理
            if target.type == 'person':
                fall_status = self.check_fall_for_target(target)
                current_frame_fall_status[target.track_id] = fall_status

                # 更新连续摔倒计数
                if fall_status == FallStatus.POSSIBLE_FALL or fall_status == FallStatus.FALL_DETECTED:
                    self.target_consecutive_fall_frames[target.track_id] = self.target_consecutive_fall_frames.get(target.track_id, 0) + 1
                else:
                    self.target_consecutive_fall_frames[target.track_id] = 0 # 非摔倒状态则重置计数

                # 更新并判断最终摔倒状态
                if self.target_consecutive_fall_frames.get(target.track_id, 0) >= self.consecutive_fall_frames_thr:
                    if self.target_fall_status.get(target.track_id) != FallStatus.FALL_DETECTED:
                        get_logger(self.get_name()).error(f"!!! FALL DETECTED for Track ID {target.track_id} !!!")
                        # (可选) 发布摔倒事件消息
                        # fall_event_msg = FallEventMsg()
                        # fall_event_msg.track_id = target.track_id
                        # fall_event_msg.timestamp = msg.header.stamp
                        # self.fall_event_publisher.publish(fall_event_msg)
                        # 新增：发布tts_make消息（5秒内只发一次）
                        now = time.time()
                        if now - self.last_tts_publish_time > 5:
                            tts_msg = String()
                            tts_msg.data = "小朋友，你摔倒了吗？"
                            self.tts_make_pub.publish(tts_msg)
                            self.last_tts_publish_time = now

                    self.target_fall_status[target.track_id] = FallStatus.FALL_DETECTED
                elif fall_status == FallStatus.POSSIBLE_FALL:
                     if self.target_fall_status.get(target.track_id) == FallStatus.NORMAL:
                          get_logger(self.get_name()).warn(f"Possible fall for Track ID {target.track_id}. Consecutive frames: {self.target_consecutive_fall_frames.get(target.track_id, 0)}")
                     self.target_fall_status[target.track_id] = FallStatus.POSSIBLE_FALL
                else:
                    if self.target_fall_status.get(target.track_id) != FallStatus.NORMAL:
                         get_logger(self.get_name()).info(f"Track ID {target.track_id} status back to NORMAL.")
                    self.target_fall_status[target.track_id] = FallStatus.NORMAL

        # 清理已消失目标的记录 (可选，根据实际需求决定是否清理)
        # disappeared_track_ids = set(self.target_fall_status.keys()) - set(current_frame_fall_status.keys())
        # for track_id in disappeared_track_ids:
        #     del self.target_fall_status[track_id]
        #     if track_id in self.target_consecutive_fall_frames:
        #          del self.target_consecutive_fall_frames[track_id]


    def check_fall_for_target(self, target):
        # 根据目标数据判断是否疑似摔倒

        has_body_roi = False
        body_rect = None
        for roi in target.rois:
            if roi.type == 'body':
                has_body_roi = True
                body_rect = roi.rect
                break

        has_body_kps = False
        body_kps_points = None
        for point_group in target.points:
             if point_group.type == 'body_kps':
                 has_body_kps = True
                 body_kps_points = point_group.point # 这是一个 Point 对象的列表
                 break


        possible_fall_conditions_met = 0 # 满足的疑似摔倒条件计数
        
        # 条件1: 高宽比判断 (如果有人体边界框)
        if has_body_roi and body_rect.height > 0:
            aspect_ratio = float(body_rect.width) / body_rect.height
            get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Aspect Ratio ({aspect_ratio:.2f})")
            if aspect_ratio > self.aspect_ratio_threshold:
                # get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Aspect Ratio ({aspect_ratio:.2f}) > Threshold ({self.aspect_ratio_threshold:.2f})")
                possible_fall_conditions_met += 1

        # 条件2: 姿态角度判断 (如果有人体关键点)
        # if has_body_kps and len(body_kps_points) > 0:
        #     # pose_angle_vs_vertical = self.calculate_pose_angle_vs_vertical(body_kps_points)
        #     # if pose_angle_vs_vertical is not None:
        #     #     get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Pose Angle ({pose_angle_vs_vertical:.2f} deg)")
        #     # if pose_angle_vs_vertical is not None and abs(pose_angle_vs_vertical) > self.angle_threshold_deg:
        #     #     # get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Pose Angle ({pose_angle_vs_vertical:.2f} deg) > Threshold ({self.angle_threshold_deg:.2f} deg)")
        #     #     possible_fall_conditions_met += 1

        # 如果同时满足两个条件，认为是疑似摔倒
        if possible_fall_conditions_met > 0:
            return FallStatus.POSSIBLE_FALL
        else:
            return FallStatus.NORMAL


    def calculate_pose_angle_vs_vertical(self, keypoints):
        # 根据关键点计算姿态角度 (示例: 使用骨盆和颈部关键点)
        #hip_kps_idx = 5 # 示例：假设骨盆关键点索引为 5
        #neck_kps_idx = 0 # 示例：假设颈部关键点索引为 0

        if len(keypoints) <= 13:
             get_logger(self.get_name()).warn("Keypoints list is too short to get hip/neck points.")
             return None # 关键点不足

       
        hip_arve_x = (keypoints[5].x+keypoints[6].x)/2
        hip_arve_y = (keypoints[5].y+keypoints[6].y)/2
        neck_arve_x = (keypoints[11].x+keypoints[12].x)/2
        neck_arve_y = (keypoints[11].y+keypoints[12].y)/2

        # 检查关键点是否有效 (例如，是否有非零坐标或置信度)
        # 这里简单检查y坐标是否有差异，如果xy都为0，可能点无效
        if hip_arve_x == 0.0 and hip_arve_y == 0.0 and neck_arve_x == 0.0 and neck_arve_y == 0.0:
             get_logger(self.get_name()).warn("Hip and Neck keypoints seem invalid (all zero).")
             return None

        # 计算骨盆到颈部的向量
        dx = neck_arve_x - hip_arve_x
        dy = neck_arve_y - hip_arve_y

        if dx == 0 and dy == 0: # 避免 atan2(0,0)
             get_logger(self.get_name()).warn("Hip and Neck keypoints are at the same location.")
             return None

        # 计算向量与垂直方向的夹角 (atan2(x, y))
        angle_rad = math.atan2(dx, dy)
        angle_deg = math.degrees(angle_rad)

        # 调整角度范围到 -90 到 90 度，0度代表垂直向上
        # 如果 dy 是负的（颈部在骨盆上方），角度应该在 -90到90
        # 如果 dy 是正的（颈部在骨盆下方，不常见），角度可能在90到-90 (经过atan2处理)
        # 这里的目的是计算与**垂直**方向的偏差，所以abs(angle_deg) 接近 90 意味着接近水平，可能是摔倒
        # abs(angle_deg) 接近 0 意味着接近垂直，可能是站立/坐着
        # 根据你的实际需求和坐标系定义，可能需要调整这里的逻辑

        # 示例：简单返回计算出的与垂直方向的夹角
        return angle_deg


def main(args=None):
    rclpy.init(args=args)

    fall_detector_node = FallDetectorNode()

    rclpy.spin(fall_detector_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    fall_detector_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()





# import rclpy
# from rclpy.node import Node
# from rclpy.logging import get_logger

# from ai_msgs.msg import PerceptionTargets # 导入感知消息类型

# import math # 用于数学计算

# # 定义摔倒状态
# class FallStatus:
#     NORMAL = 0
#     POSSIBLE_FALL = 1 # 疑似摔倒
#     FALL_DETECTED = 2  # 确认摔倒

# class FallDetectorNode(Node):

#     def __init__(self):
#         super().__init__('fall_detector_node') # 初始化节点名称

#         # 声明参数 (可以根据需要添加更多，并通过launch文件或yaml文件配置)
#         self.declare_parameter('aspect_ratio_threshold', 1.5) # 宽度/高度 > 1.5 视为可能摔倒 (侧躺)
#         self.declare_parameter('angle_threshold_deg', 45.0) # 骨盆-颈部连线与垂直方向夹角 > 45度视为可能摔倒
#         self.declare_parameter('consecutive_fall_frames_thr', 5) # 连续多少帧满足条件视为确认摔倒
#         self.declare_parameter('vertical_span_ratio_threshold', 0.3) # 关键点垂直跨度 / 人体框高度 < 0.3 视为可能摔倒

#         self.aspect_ratio_threshold = self.get_parameter('aspect_ratio_threshold').get_parameter_value().double_value
#         self.angle_threshold_deg = self.get_parameter('angle_threshold_deg').get_parameter_value().double_value
#         self.consecutive_fall_frames_thr = self.get_parameter('consecutive_fall_frames_thr').get_parameter_value().integer_value
#         self.vertical_span_ratio_threshold = self.get_parameter('vertical_span_ratio_threshold').get_parameter_value().double_value

#         get_logger(self.get_name()).info(f"FallDetectorNode initialized with parameters: aspect_ratio_threshold={self.aspect_ratio_threshold}, angle_threshold_deg={self.angle_threshold_deg}, consecutive_fall_frames_thr={self.consecutive_fall_frames_thr}, vertical_span_ratio_threshold={self.vertical_span_ratio_threshold}") # 更新日志输出

#         # 创建订阅者，订阅 PerceptionTargets 话题
#         # 请根据你的实际话题名称修改 '/ai_msgs/msg/PerceptionTargets'
#         self.subscription = self.create_subscription(
#             PerceptionTargets,
#             '/hobot_mono2d_body_detection', # 替换成你的PerceptionTargets话题名称
#             self.perception_targets_callback,
#             10) # QoS history depth
#         self.subscription # prevent unused variable warning

#         # 保存每个目标的摔倒状态和连续计数
#         self.target_fall_status = {} # {track_id: FallStatus}
#         self.target_consecutive_fall_frames = {} # {track_id: count}

#         # (可选) 创建发布者，用于发布摔倒检测结果
#         # 你可能需要定义一个新的消息类型来发布摔倒信息
#         # self.fall_event_publisher = self.create_publisher(FallEventMsg, '/fall_events', 10)


#     def perception_targets_callback(self, msg):
#         # get_logger(self.get_name()).info(f"Received PerceptionTargets message with {len(msg.targets)} targets")

#         current_frame_fall_status = {} # 记录当前帧每个目标的摔倒状态

#         # 遍历消息中的每个目标
#         for target in msg.targets:
#             # 只对类型为 person 的目标进行处理
#             if target.type == 'person':
#                 fall_status = self.check_fall_for_target(target)
#                 current_frame_fall_status[target.track_id] = fall_status

#                 # 更新连续摔倒计数
#                 if fall_status == FallStatus.POSSIBLE_FALL or fall_status == FallStatus.FALL_DETECTED:
#                     self.target_consecutive_fall_frames[target.track_id] = self.target_consecutive_fall_frames.get(target.track_id, 0) + 1
#                 else:
#                     self.target_consecutive_fall_frames[target.track_id] = 0 # 非摔倒状态则重置计数

#                 # 更新并判断最终摔倒状态
#                 if self.target_consecutive_fall_frames.get(target.track_id, 0) >= self.consecutive_fall_frames_thr:
#                     if self.target_fall_status.get(target.track_id) != FallStatus.FALL_DETECTED:
#                         get_logger(self.get_name()).error(f"!!! FALL DETECTED for Track ID {target.track_id} !!!")
#                         # (可选) 发布摔倒事件消息
#                         # fall_event_msg = FallEventMsg()
#                         # fall_event_msg.track_id = target.track_id
#                         # fall_event_msg.timestamp = msg.header.stamp
#                         # self.fall_event_publisher.publish(fall_event_msg)

#                     self.target_fall_status[target.track_id] = FallStatus.FALL_DETECTED
#                 elif fall_status == FallStatus.POSSIBLE_FALL:
#                      if self.target_fall_status.get(target.track_id) == FallStatus.NORMAL:
#                           get_logger(self.get_name()).warn(f"Possible fall for Track ID {target.track_id}. Consecutive frames: {self.target_consecutive_fall_frames.get(target.track_id, 0)}")
#                      self.target_fall_status[target.track_id] = FallStatus.POSSIBLE_FALL
#                 else:
#                     if self.target_fall_status.get(target.track_id) != FallStatus.NORMAL:
#                          get_logger(self.get_name()).info(f"Track ID {target.track_id} status back to NORMAL.")
#                     self.target_fall_status[target.track_id] = FallStatus.NORMAL

#         # 清理已消失目标的记录 (可选，根据实际需求决定是否清理)
#         # disappeared_track_ids = set(self.target_fall_status.keys()) - set(current_frame_fall_status.keys())
#         # for track_id in disappeared_track_ids:
#         #     del self.target_fall_status[track_id]
#         #     if track_id in self.target_consecutive_fall_frames:
#         #          del self.target_consecutive_fall_frames[track_id]


#     def check_fall_for_target(self, target):
#         # 根据目标数据判断是否疑似摔倒

#         has_body_roi = False
#         body_rect = None
#         for roi in target.rois:
#             if roi.type == 'body':
#                 has_body_roi = True
#                 body_rect = roi.rect # geometry_msgs/msg/Pose2D
#                 break

#         has_body_kps = False
#         body_kps_points = None
#         for point_group in target.points:
#              if point_group.type == 'body_kps':
#                  has_body_kps = True
#                  body_kps_points = point_group.point # 这是一个 Point 对象的列表
#                  break

#         # 必须同时有人体框和关键点才能进行基于垂直跨度的判断
#         if not has_body_roi or not has_body_kps or body_rect.height <= 0 or not body_kps_points:
#              # 如果没有人体框或关键点，或者人体框高度无效，则无法判断摔倒，返回正常状态
#              # get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Missing body ROI/KPS or invalid height for fall check.")
#              return FallStatus.NORMAL


#         possible_fall_conditions_met = 0 # 满足的疑似摔倒条件计数

#         # 条件1: 高宽比判断 (可选，可以保留或移除)
#         # if body_rect.height > 0: # 避免除以零，前面已经检查过
#         #     aspect_ratio = float(body_rect.width) / body_rect.height
#         #     if aspect_ratio > self.aspect_ratio_threshold:
#         #          get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Aspect Ratio ({aspect_ratio:.2f}) > Threshold ({self.aspect_ratio_threshold:.2f})")
#         #         possible_fall_conditions_met += 1

#         # 新的条件: 关键点垂直跨度与人体框高度的比例
#         min_y = float('inf')
#         max_y = float('-inf')
#         valid_kps_count = 0
#         for kp in body_kps_points:
#             # 可以选择只考虑特定关键点（如头部、躯干、脚部），或者考虑所有关键点
#             # 简单起见，这里考虑所有关键点
#             # TODO: 根据你的关键点模型定义，可能需要排除置信度低的关键点或特定不参与判断的关键点
#             if kp.x != 0.0 or kp.y != 0.0: # 简单检查关键点是否为默认无效值
#                  min_y = min(min_y, kp.y)
#                  max_y = max(max_y, kp.y)
#                  valid_kps_count += 1

#         if valid_kps_count > 1: # 至少需要两个有效关键点来计算跨度
#             vertical_span = max_y - min_y
#             vertical_span_ratio = vertical_span / body_rect.height

#             # 当垂直跨度比例小于阈值时，视为可能摔倒
#             if vertical_span_ratio < self.vertical_span_ratio_threshold:
#                  get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Vertical Span Ratio ({vertical_span_ratio:.2f}) < Threshold ({self.vertical_span_ratio_threshold:.2f}). Body Height: {body_rect.height}, Span: {vertical_span}")
#                  possible_fall_conditions_met += 1 # 满足摔倒条件

#         # 条件2: 姿态角度判断 (可选，可以保留或移除，作为辅助判断)
#         # 如果只使用垂直跨度，可以移除姿态角度判断
#         # if has_body_kps and len(body_kps_points) > 1: # 确保有足够的关键点用于角度计算
#         #      pose_angle_vs_vertical = self.calculate_pose_angle_vs_vertical(body_kps_points)
#         #      if pose_angle_vs_vertical is not None and abs(pose_angle_vs_vertical) > self.angle_threshold_deg:
#         #           get_logger(self.get_name()).debug(f"Track ID {target.track_id}: Pose Angle ({pose_angle_vs_vertical:.2f} deg) > Threshold ({self.angle_threshold_deg:.2f} deg)")
#         #          possible_fall_conditions_met += 1


#         # 如果至少满足一个新的（或保留的）条件，认为是疑似摔倒
#         if possible_fall_conditions_met > 0:
#             return FallStatus.POSSIBLE_FALL
#         else:
#             return FallStatus.NORMAL

#     # calculate_pose_angle_vs_vertical 方法可以保留作为辅助判断，或者如果你决定完全依赖垂直跨度，可以移除
#     def calculate_pose_angle_vs_vertical(self, keypoints):
#          # ... (代码保持不变，或者根据需要修改关键点索引) ...
#          # !! 重要 !! 确保这里的关键点索引和计算逻辑与你的模型输出一致
#          hip_kps_idx = 5 # 示例索引
#          neck_kps_idx = 0 # 示例索引
#          # ... rest of the function ...
#          pass # Placeholder if you keep the function


#     # def calculate_pose_angle_vs_vertical(self, keypoints):
#     #     # 根据关键点计算姿态角度 (示例: 使用骨盆和颈部关键点)
#     #     # !! 注意 !! 这里的关键点索引 (5, 0) 需要根据你的AI模型实际输出的 body_kps 索引来调整
#     #     # 请查阅你的地平线AI模型文档，了解 body_kps 列表中的每个索引代表什么关节
#     #     hip_kps_idx = 5 # 示例：假设骨盆关键点索引为 5
#     #     neck_kps_idx = 0 # 示例：假设颈部关键点索引为 0

#     #     if len(keypoints) <= max(hip_kps_idx, neck_kps_idx):
#     #          get_logger(self.get_name()).warn("Keypoints list is too short to get hip/neck points.")
#     #          return None # 关键点不足

#     #     hip_point = keypoints[hip_kps_idx]
#     #     neck_point = keypoints[neck_kps_idx]

#     #     # 检查关键点是否有效 (例如，是否有非零坐标或置信度)
#     #     # 这里简单检查y坐标是否有差异，如果xy都为0，可能点无效
#     #     if hip_point.x == 0.0 and hip_point.y == 0.0 and neck_point.x == 0.0 and neck_point.y == 0.0:
#     #          get_logger(self.get_name()).warn("Hip and Neck keypoints seem invalid (all zero).")
#     #          return None

#     #     # 计算骨盆到颈部的向量
#     #     dx = neck_point.x - hip_point.x
#     #     dy = neck_point.y - hip_point.y

#     #     if dx == 0 and dy == 0: # 避免 atan2(0,0)
#     #          get_logger(self.get_name()).warn("Hip and Neck keypoints are at the same location.")
#     #          return None

#     #     # 计算向量与垂直方向的夹角 (atan2(x, y))
#     #     angle_rad = math.atan2(dx, dy)
#     #     angle_deg = math.degrees(angle_rad)

#     #     # 调整角度范围到 -90 到 90 度，0度代表垂直向上
#     #     # 如果 dy 是负的（颈部在骨盆上方），角度应该在 -90到90
#     #     # 如果 dy 是正的（颈部在骨盆下方，不常见），角度可能在90到-90 (经过atan2处理)
#     #     # 这里的目的是计算与**垂直**方向的偏差，所以abs(angle_deg) 接近 90 意味着接近水平，可能是摔倒
#     #     # abs(angle_deg) 接近 0 意味着接近垂直，可能是站立/坐着
#     #     # 根据你的实际需求和坐标系定义，可能需要调整这里的逻辑

#     #     # 示例：简单返回计算出的与垂直方向的夹角
#     #     return angle_deg


# def main(args=None):
#     rclpy.init(args=args)

#     fall_detector_node = FallDetectorNode()

#     rclpy.spin(fall_detector_node)

#     # Destroy the node explicitly
#     # (optional - otherwise it will be done automatically
#     # when the garbage collector destroys the node object)
#     fall_detector_node.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()





