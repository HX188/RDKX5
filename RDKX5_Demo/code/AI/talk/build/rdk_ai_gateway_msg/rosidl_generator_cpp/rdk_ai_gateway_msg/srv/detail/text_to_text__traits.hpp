// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#ifndef RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__TRAITS_HPP_
#define RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rdk_ai_gateway_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const TextToText_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: input
  {
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
    out << ", ";
  }

  // member: model
  {
    out << "model: ";
    rosidl_generator_traits::value_to_yaml(msg.model, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TextToText_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input: ";
    rosidl_generator_traits::value_to_yaml(msg.input, out);
    out << "\n";
  }

  // member: model
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model: ";
    rosidl_generator_traits::value_to_yaml(msg.model, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TextToText_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rosidl_generator_traits
{

[[deprecated("use rdk_ai_gateway_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rdk_ai_gateway_msg::srv::TextToText_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rdk_ai_gateway_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rdk_ai_gateway_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rdk_ai_gateway_msg::srv::TextToText_Request & msg)
{
  return rdk_ai_gateway_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rdk_ai_gateway_msg::srv::TextToText_Request>()
{
  return "rdk_ai_gateway_msg::srv::TextToText_Request";
}

template<>
inline const char * name<rdk_ai_gateway_msg::srv::TextToText_Request>()
{
  return "rdk_ai_gateway_msg/srv/TextToText_Request";
}

template<>
struct has_fixed_size<rdk_ai_gateway_msg::srv::TextToText_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rdk_ai_gateway_msg::srv::TextToText_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rdk_ai_gateway_msg::srv::TextToText_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rdk_ai_gateway_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const TextToText_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: output
  {
    out << "output: ";
    rosidl_generator_traits::value_to_yaml(msg.output, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TextToText_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output: ";
    rosidl_generator_traits::value_to_yaml(msg.output, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TextToText_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rosidl_generator_traits
{

[[deprecated("use rdk_ai_gateway_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rdk_ai_gateway_msg::srv::TextToText_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rdk_ai_gateway_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rdk_ai_gateway_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const rdk_ai_gateway_msg::srv::TextToText_Response & msg)
{
  return rdk_ai_gateway_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rdk_ai_gateway_msg::srv::TextToText_Response>()
{
  return "rdk_ai_gateway_msg::srv::TextToText_Response";
}

template<>
inline const char * name<rdk_ai_gateway_msg::srv::TextToText_Response>()
{
  return "rdk_ai_gateway_msg/srv/TextToText_Response";
}

template<>
struct has_fixed_size<rdk_ai_gateway_msg::srv::TextToText_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rdk_ai_gateway_msg::srv::TextToText_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rdk_ai_gateway_msg::srv::TextToText_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rdk_ai_gateway_msg::srv::TextToText>()
{
  return "rdk_ai_gateway_msg::srv::TextToText";
}

template<>
inline const char * name<rdk_ai_gateway_msg::srv::TextToText>()
{
  return "rdk_ai_gateway_msg/srv/TextToText";
}

template<>
struct has_fixed_size<rdk_ai_gateway_msg::srv::TextToText>
  : std::integral_constant<
    bool,
    has_fixed_size<rdk_ai_gateway_msg::srv::TextToText_Request>::value &&
    has_fixed_size<rdk_ai_gateway_msg::srv::TextToText_Response>::value
  >
{
};

template<>
struct has_bounded_size<rdk_ai_gateway_msg::srv::TextToText>
  : std::integral_constant<
    bool,
    has_bounded_size<rdk_ai_gateway_msg::srv::TextToText_Request>::value &&
    has_bounded_size<rdk_ai_gateway_msg::srv::TextToText_Response>::value
  >
{
};

template<>
struct is_service<rdk_ai_gateway_msg::srv::TextToText>
  : std::true_type
{
};

template<>
struct is_service_request<rdk_ai_gateway_msg::srv::TextToText_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rdk_ai_gateway_msg::srv::TextToText_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__TRAITS_HPP_
