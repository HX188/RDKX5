// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wheeltec_mic_msg:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__BUILDER_HPP_
#define WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wheeltec_mic_msg/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wheeltec_mic_msg
{

namespace msg
{

namespace builder
{

class Init_Position_distance
{
public:
  explicit Init_Position_distance(::wheeltec_mic_msg::msg::Position & msg)
  : msg_(msg)
  {}
  ::wheeltec_mic_msg::msg::Position distance(::wheeltec_mic_msg::msg::Position::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wheeltec_mic_msg::msg::Position msg_;
};

class Init_Position_angle_y
{
public:
  explicit Init_Position_angle_y(::wheeltec_mic_msg::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_distance angle_y(::wheeltec_mic_msg::msg::Position::_angle_y_type arg)
  {
    msg_.angle_y = std::move(arg);
    return Init_Position_distance(msg_);
  }

private:
  ::wheeltec_mic_msg::msg::Position msg_;
};

class Init_Position_angle_x
{
public:
  Init_Position_angle_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_angle_y angle_x(::wheeltec_mic_msg::msg::Position::_angle_x_type arg)
  {
    msg_.angle_x = std::move(arg);
    return Init_Position_angle_y(msg_);
  }

private:
  ::wheeltec_mic_msg::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wheeltec_mic_msg::msg::Position>()
{
  return wheeltec_mic_msg::msg::builder::Init_Position_angle_x();
}

}  // namespace wheeltec_mic_msg

#endif  // WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__BUILDER_HPP_
