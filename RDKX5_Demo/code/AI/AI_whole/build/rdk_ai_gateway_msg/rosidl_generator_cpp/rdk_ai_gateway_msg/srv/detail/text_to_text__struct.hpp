// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice

#ifndef RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_HPP_
#define RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Request __attribute__((deprecated))
#else
# define DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Request __declspec(deprecated)
#endif

namespace rdk_ai_gateway_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TextToText_Request_
{
  using Type = TextToText_Request_<ContainerAllocator>;

  explicit TextToText_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = "";
      this->model = "";
    }
  }

  explicit TextToText_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : input(_alloc),
    model(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input = "";
      this->model = "";
    }
  }

  // field types and members
  using _input_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _input_type input;
  using _model_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_type model;

  // setters for named parameter idiom
  Type & set__input(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->input = _arg;
    return *this;
  }
  Type & set__model(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Request
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Request
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TextToText_Request_ & other) const
  {
    if (this->input != other.input) {
      return false;
    }
    if (this->model != other.model) {
      return false;
    }
    return true;
  }
  bool operator!=(const TextToText_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TextToText_Request_

// alias to use template instance with default allocator
using TextToText_Request =
  rdk_ai_gateway_msg::srv::TextToText_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rdk_ai_gateway_msg


#ifndef _WIN32
# define DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Response __attribute__((deprecated))
#else
# define DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Response __declspec(deprecated)
#endif

namespace rdk_ai_gateway_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TextToText_Response_
{
  using Type = TextToText_Response_<ContainerAllocator>;

  explicit TextToText_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  explicit TextToText_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  // field types and members
  using _output_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_type output;

  // setters for named parameter idiom
  Type & set__output(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Response
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rdk_ai_gateway_msg__srv__TextToText_Response
    std::shared_ptr<rdk_ai_gateway_msg::srv::TextToText_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TextToText_Response_ & other) const
  {
    if (this->output != other.output) {
      return false;
    }
    return true;
  }
  bool operator!=(const TextToText_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TextToText_Response_

// alias to use template instance with default allocator
using TextToText_Response =
  rdk_ai_gateway_msg::srv::TextToText_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

namespace rdk_ai_gateway_msg
{

namespace srv
{

struct TextToText
{
  using Request = rdk_ai_gateway_msg::srv::TextToText_Request;
  using Response = rdk_ai_gateway_msg::srv::TextToText_Response;
};

}  // namespace srv

}  // namespace rdk_ai_gateway_msg

#endif  // RDK_AI_GATEWAY_MSG__SRV__DETAIL__TEXT_TO_TEXT__STRUCT_HPP_
