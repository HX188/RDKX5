// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#ifndef RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
cdr_serialize(
  const rdk_ai_gateway_msg::srv::TextToText_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rdk_ai_gateway_msg::srv::TextToText_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
get_serialized_size(
  const rdk_ai_gateway_msg::srv::TextToText_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
max_serialized_size_TextToText_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
cdr_serialize(
  const rdk_ai_gateway_msg::srv::TextToText_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rdk_ai_gateway_msg::srv::TextToText_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
get_serialized_size(
  const rdk_ai_gateway_msg::srv::TextToText_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
max_serialized_size_TextToText_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rdk_ai_gateway_msg
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText)();

#ifdef __cplusplus
}
#endif

#endif  // RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
