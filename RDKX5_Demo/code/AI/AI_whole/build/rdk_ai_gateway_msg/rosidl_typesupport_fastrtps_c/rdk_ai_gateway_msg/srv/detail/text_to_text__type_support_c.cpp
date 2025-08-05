// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // input, model
#include "rosidl_runtime_c/string_functions.h"  // input, model

// forward declare type support functions


using _TextToText_Request__ros_msg_type = rdk_ai_gateway_msg__srv__TextToText_Request;

static bool _TextToText_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TextToText_Request__ros_msg_type * ros_message = static_cast<const _TextToText_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: input
  {
    const rosidl_runtime_c__String * str = &ros_message->input;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: model
  {
    const rosidl_runtime_c__String * str = &ros_message->model;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TextToText_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TextToText_Request__ros_msg_type * ros_message = static_cast<_TextToText_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: input
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->input.data) {
      rosidl_runtime_c__String__init(&ros_message->input);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->input,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'input'\n");
      return false;
    }
  }

  // Field name: model
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->model.data) {
      rosidl_runtime_c__String__init(&ros_message->model);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->model,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'model'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rdk_ai_gateway_msg
size_t get_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TextToText_Request__ros_msg_type * ros_message = static_cast<const _TextToText_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name input
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->input.size + 1);
  // field.name model
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->model.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TextToText_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rdk_ai_gateway_msg
size_t max_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: input
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: model
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rdk_ai_gateway_msg__srv__TextToText_Request;
    is_plain =
      (
      offsetof(DataType, model) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TextToText_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TextToText_Request = {
  "rdk_ai_gateway_msg::srv",
  "TextToText_Request",
  _TextToText_Request__cdr_serialize,
  _TextToText_Request__cdr_deserialize,
  _TextToText_Request__get_serialized_size,
  _TextToText_Request__max_serialized_size
};

static rosidl_message_type_support_t _TextToText_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TextToText_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rdk_ai_gateway_msg, srv, TextToText_Request)() {
  return &_TextToText_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // output
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // output

// forward declare type support functions


using _TextToText_Response__ros_msg_type = rdk_ai_gateway_msg__srv__TextToText_Response;

static bool _TextToText_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TextToText_Response__ros_msg_type * ros_message = static_cast<const _TextToText_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: output
  {
    const rosidl_runtime_c__String * str = &ros_message->output;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TextToText_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TextToText_Response__ros_msg_type * ros_message = static_cast<_TextToText_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: output
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->output.data) {
      rosidl_runtime_c__String__init(&ros_message->output);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->output,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'output'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rdk_ai_gateway_msg
size_t get_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TextToText_Response__ros_msg_type * ros_message = static_cast<const _TextToText_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name output
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->output.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TextToText_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rdk_ai_gateway_msg
size_t max_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: output
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rdk_ai_gateway_msg__srv__TextToText_Response;
    is_plain =
      (
      offsetof(DataType, output) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TextToText_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rdk_ai_gateway_msg__srv__TextToText_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TextToText_Response = {
  "rdk_ai_gateway_msg::srv",
  "TextToText_Response",
  _TextToText_Response__cdr_serialize,
  _TextToText_Response__cdr_deserialize,
  _TextToText_Response__get_serialized_size,
  _TextToText_Response__max_serialized_size
};

static rosidl_message_type_support_t _TextToText_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TextToText_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rdk_ai_gateway_msg, srv, TextToText_Response)() {
  return &_TextToText_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rdk_ai_gateway_msg/srv/text_to_text.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t TextToText__callbacks = {
  "rdk_ai_gateway_msg::srv",
  "TextToText",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rdk_ai_gateway_msg, srv, TextToText_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rdk_ai_gateway_msg, srv, TextToText_Response)(),
};

static rosidl_service_type_support_t TextToText__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &TextToText__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rdk_ai_gateway_msg, srv, TextToText)() {
  return &TextToText__handle;
}

#if defined(__cplusplus)
}
#endif
