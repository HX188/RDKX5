// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TextToText_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TextToText_Request_type_support_ids_t;

static const _TextToText_Request_type_support_ids_t _TextToText_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TextToText_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TextToText_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TextToText_Request_type_support_symbol_names_t _TextToText_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rdk_ai_gateway_msg, srv, TextToText_Request)),
  }
};

typedef struct _TextToText_Request_type_support_data_t
{
  void * data[2];
} _TextToText_Request_type_support_data_t;

static _TextToText_Request_type_support_data_t _TextToText_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TextToText_Request_message_typesupport_map = {
  2,
  "rdk_ai_gateway_msg",
  &_TextToText_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TextToText_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TextToText_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TextToText_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TextToText_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rdk_ai_gateway_msg::srv::TextToText_Request>()
{
  return &::rdk_ai_gateway_msg::srv::rosidl_typesupport_cpp::TextToText_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, rdk_ai_gateway_msg, srv, TextToText_Request)() {
  return get_message_type_support_handle<rdk_ai_gateway_msg::srv::TextToText_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TextToText_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TextToText_Response_type_support_ids_t;

static const _TextToText_Response_type_support_ids_t _TextToText_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TextToText_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TextToText_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TextToText_Response_type_support_symbol_names_t _TextToText_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rdk_ai_gateway_msg, srv, TextToText_Response)),
  }
};

typedef struct _TextToText_Response_type_support_data_t
{
  void * data[2];
} _TextToText_Response_type_support_data_t;

static _TextToText_Response_type_support_data_t _TextToText_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TextToText_Response_message_typesupport_map = {
  2,
  "rdk_ai_gateway_msg",
  &_TextToText_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TextToText_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TextToText_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TextToText_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TextToText_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rdk_ai_gateway_msg::srv::TextToText_Response>()
{
  return &::rdk_ai_gateway_msg::srv::rosidl_typesupport_cpp::TextToText_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, rdk_ai_gateway_msg, srv, TextToText_Response)() {
  return get_message_type_support_handle<rdk_ai_gateway_msg::srv::TextToText_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TextToText_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TextToText_type_support_ids_t;

static const _TextToText_type_support_ids_t _TextToText_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TextToText_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TextToText_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TextToText_type_support_symbol_names_t _TextToText_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rdk_ai_gateway_msg, srv, TextToText)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rdk_ai_gateway_msg, srv, TextToText)),
  }
};

typedef struct _TextToText_type_support_data_t
{
  void * data[2];
} _TextToText_type_support_data_t;

static _TextToText_type_support_data_t _TextToText_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TextToText_service_typesupport_map = {
  2,
  "rdk_ai_gateway_msg",
  &_TextToText_service_typesupport_ids.typesupport_identifier[0],
  &_TextToText_service_typesupport_symbol_names.symbol_name[0],
  &_TextToText_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TextToText_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TextToText_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<rdk_ai_gateway_msg::srv::TextToText>()
{
  return &::rdk_ai_gateway_msg::srv::rosidl_typesupport_cpp::TextToText_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, rdk_ai_gateway_msg, srv, TextToText)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<rdk_ai_gateway_msg::srv::TextToText>();
}

#ifdef __cplusplus
}
#endif
