// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__rosidl_typesupport_introspection_c.h"
#include "rdk_ai_gateway_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__functions.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.h"


// Include directives for member types
// Member `input`
// Member `model`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rdk_ai_gateway_msg__srv__TextToText_Request__init(message_memory);
}

void rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_fini_function(void * message_memory)
{
  rdk_ai_gateway_msg__srv__TextToText_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_member_array[2] = {
  {
    "input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rdk_ai_gateway_msg__srv__TextToText_Request, input),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "model",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rdk_ai_gateway_msg__srv__TextToText_Request, model),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_members = {
  "rdk_ai_gateway_msg__srv",  // message namespace
  "TextToText_Request",  // message name
  2,  // number of fields
  sizeof(rdk_ai_gateway_msg__srv__TextToText_Request),
  rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_member_array,  // message members
  rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_type_support_handle = {
  0,
  &rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rdk_ai_gateway_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Request)() {
  if (!rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_type_support_handle.typesupport_identifier) {
    rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rdk_ai_gateway_msg__srv__TextToText_Request__rosidl_typesupport_introspection_c__TextToText_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__functions.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.h"


// Include directives for member types
// Member `output`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rdk_ai_gateway_msg__srv__TextToText_Response__init(message_memory);
}

void rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_fini_function(void * message_memory)
{
  rdk_ai_gateway_msg__srv__TextToText_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_member_array[1] = {
  {
    "output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rdk_ai_gateway_msg__srv__TextToText_Response, output),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_members = {
  "rdk_ai_gateway_msg__srv",  // message namespace
  "TextToText_Response",  // message name
  1,  // number of fields
  sizeof(rdk_ai_gateway_msg__srv__TextToText_Response),
  rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_member_array,  // message members
  rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_type_support_handle = {
  0,
  &rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rdk_ai_gateway_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Response)() {
  if (!rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_type_support_handle.typesupport_identifier) {
    rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rdk_ai_gateway_msg__srv__TextToText_Response__rosidl_typesupport_introspection_c__TextToText_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rdk_ai_gateway_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_members = {
  "rdk_ai_gateway_msg__srv",  // service namespace
  "TextToText",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_Request_message_type_support_handle,
  NULL  // response message
  // rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_Response_message_type_support_handle
};

static rosidl_service_type_support_t rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_type_support_handle = {
  0,
  &rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rdk_ai_gateway_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText)() {
  if (!rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_type_support_handle.typesupport_identifier) {
    rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rdk_ai_gateway_msg, srv, TextToText_Response)()->data;
  }

  return &rdk_ai_gateway_msg__srv__detail__text_to_text__rosidl_typesupport_introspection_c__TextToText_service_type_support_handle;
}
