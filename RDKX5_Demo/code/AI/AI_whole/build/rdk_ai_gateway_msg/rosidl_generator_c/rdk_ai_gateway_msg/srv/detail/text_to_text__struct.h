// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#ifndef RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_H_
#define RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'input'
// Member 'model'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TextToText in the package rdk_ai_gateway_msg.
typedef struct rdk_ai_gateway_msg__srv__TextToText_Request
{
  rosidl_runtime_c__String input;
  rosidl_runtime_c__String model;
} rdk_ai_gateway_msg__srv__TextToText_Request;

// Struct for a sequence of rdk_ai_gateway_msg__srv__TextToText_Request.
typedef struct rdk_ai_gateway_msg__srv__TextToText_Request__Sequence
{
  rdk_ai_gateway_msg__srv__TextToText_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rdk_ai_gateway_msg__srv__TextToText_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'output'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TextToText in the package rdk_ai_gateway_msg.
typedef struct rdk_ai_gateway_msg__srv__TextToText_Response
{
  rosidl_runtime_c__String output;
} rdk_ai_gateway_msg__srv__TextToText_Response;

// Struct for a sequence of rdk_ai_gateway_msg__srv__TextToText_Response.
typedef struct rdk_ai_gateway_msg__srv__TextToText_Response__Sequence
{
  rdk_ai_gateway_msg__srv__TextToText_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rdk_ai_gateway_msg__srv__TextToText_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_H_
