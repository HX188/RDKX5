// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#ifndef RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__BUILDER_HPP_
#define RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rdk_ai_gateway_msg/srv/detail/text_to_text__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace builder
{

class Init_TextToText_Request_model
{
public:
  explicit Init_TextToText_Request_model(::rdk_ai_gateway_msg::srv::TextToText_Request & msg)
  : msg_(msg)
  {}
  ::rdk_ai_gateway_msg::srv::TextToText_Request model(::rdk_ai_gateway_msg::srv::TextToText_Request::_model_type arg)
  {
    msg_.model = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rdk_ai_gateway_msg::srv::TextToText_Request msg_;
};

class Init_TextToText_Request_input
{
public:
  Init_TextToText_Request_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TextToText_Request_model input(::rdk_ai_gateway_msg::srv::TextToText_Request::_input_type arg)
  {
    msg_.input = std::move(arg);
    return Init_TextToText_Request_model(msg_);
  }

private:
  ::rdk_ai_gateway_msg::srv::TextToText_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rdk_ai_gateway_msg::srv::TextToText_Request>()
{
  return rdk_ai_gateway_msg::srv::builder::Init_TextToText_Request_input();
}

}  // namespace rdk_ai_gateway_msg


namespace rdk_ai_gateway_msg
{

namespace srv
{

namespace builder
{

class Init_TextToText_Response_output
{
public:
  Init_TextToText_Response_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rdk_ai_gateway_msg::srv::TextToText_Response output(::rdk_ai_gateway_msg::srv::TextToText_Response::_output_type arg)
  {
    msg_.output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rdk_ai_gateway_msg::srv::TextToText_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rdk_ai_gateway_msg::srv::TextToText_Response>()
{
  return rdk_ai_gateway_msg::srv::builder::Init_TextToText_Response_output();
}

}  // namespace rdk_ai_gateway_msg

#endif  // RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__BUILDER_HPP_
