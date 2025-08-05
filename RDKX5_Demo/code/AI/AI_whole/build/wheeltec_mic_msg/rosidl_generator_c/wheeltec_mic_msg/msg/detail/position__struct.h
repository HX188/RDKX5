// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wheeltec_mic_msg:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__STRUCT_H_
#define WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Position in the package wheeltec_mic_msg.
typedef struct wheeltec_mic_msg__msg__Position
{
  float angle_x;
  float angle_y;
  float distance;
} wheeltec_mic_msg__msg__Position;

// Struct for a sequence of wheeltec_mic_msg__msg__Position.
typedef struct wheeltec_mic_msg__msg__Position__Sequence
{
  wheeltec_mic_msg__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wheeltec_mic_msg__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WHEELTEC_MIC_MSG__MSG__DETAIL__POSITION__STRUCT_H_
