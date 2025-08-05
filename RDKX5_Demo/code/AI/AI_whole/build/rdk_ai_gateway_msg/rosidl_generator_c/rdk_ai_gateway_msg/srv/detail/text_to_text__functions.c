// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rdk_ai_gateway_msg:srv/TextToText.idl
// generated code does not contain a copyright notice
#include "rdk_ai_gateway_msg/srv/detail/text_to_text__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `input`
// Member `model`
#include "rosidl_runtime_c/string_functions.h"

bool
rdk_ai_gateway_msg__srv__TextToText_Request__init(rdk_ai_gateway_msg__srv__TextToText_Request * msg)
{
  if (!msg) {
    return false;
  }
  // input
  if (!rosidl_runtime_c__String__init(&msg->input)) {
    rdk_ai_gateway_msg__srv__TextToText_Request__fini(msg);
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__init(&msg->model)) {
    rdk_ai_gateway_msg__srv__TextToText_Request__fini(msg);
    return false;
  }
  return true;
}

void
rdk_ai_gateway_msg__srv__TextToText_Request__fini(rdk_ai_gateway_msg__srv__TextToText_Request * msg)
{
  if (!msg) {
    return;
  }
  // input
  rosidl_runtime_c__String__fini(&msg->input);
  // model
  rosidl_runtime_c__String__fini(&msg->model);
}

bool
rdk_ai_gateway_msg__srv__TextToText_Request__are_equal(const rdk_ai_gateway_msg__srv__TextToText_Request * lhs, const rdk_ai_gateway_msg__srv__TextToText_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // input
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->input), &(rhs->input)))
  {
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model), &(rhs->model)))
  {
    return false;
  }
  return true;
}

bool
rdk_ai_gateway_msg__srv__TextToText_Request__copy(
  const rdk_ai_gateway_msg__srv__TextToText_Request * input,
  rdk_ai_gateway_msg__srv__TextToText_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // input
  if (!rosidl_runtime_c__String__copy(
      &(input->input), &(output->input)))
  {
    return false;
  }
  // model
  if (!rosidl_runtime_c__String__copy(
      &(input->model), &(output->model)))
  {
    return false;
  }
  return true;
}

rdk_ai_gateway_msg__srv__TextToText_Request *
rdk_ai_gateway_msg__srv__TextToText_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Request * msg = (rdk_ai_gateway_msg__srv__TextToText_Request *)allocator.allocate(sizeof(rdk_ai_gateway_msg__srv__TextToText_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rdk_ai_gateway_msg__srv__TextToText_Request));
  bool success = rdk_ai_gateway_msg__srv__TextToText_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rdk_ai_gateway_msg__srv__TextToText_Request__destroy(rdk_ai_gateway_msg__srv__TextToText_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rdk_ai_gateway_msg__srv__TextToText_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__init(rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Request * data = NULL;

  if (size) {
    data = (rdk_ai_gateway_msg__srv__TextToText_Request *)allocator.zero_allocate(size, sizeof(rdk_ai_gateway_msg__srv__TextToText_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rdk_ai_gateway_msg__srv__TextToText_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rdk_ai_gateway_msg__srv__TextToText_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__fini(rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rdk_ai_gateway_msg__srv__TextToText_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rdk_ai_gateway_msg__srv__TextToText_Request__Sequence *
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * array = (rdk_ai_gateway_msg__srv__TextToText_Request__Sequence *)allocator.allocate(sizeof(rdk_ai_gateway_msg__srv__TextToText_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__destroy(rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__are_equal(const rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * lhs, const rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rdk_ai_gateway_msg__srv__TextToText_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rdk_ai_gateway_msg__srv__TextToText_Request__Sequence__copy(
  const rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * input,
  rdk_ai_gateway_msg__srv__TextToText_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rdk_ai_gateway_msg__srv__TextToText_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rdk_ai_gateway_msg__srv__TextToText_Request * data =
      (rdk_ai_gateway_msg__srv__TextToText_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rdk_ai_gateway_msg__srv__TextToText_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rdk_ai_gateway_msg__srv__TextToText_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rdk_ai_gateway_msg__srv__TextToText_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `output`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
rdk_ai_gateway_msg__srv__TextToText_Response__init(rdk_ai_gateway_msg__srv__TextToText_Response * msg)
{
  if (!msg) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__init(&msg->output)) {
    rdk_ai_gateway_msg__srv__TextToText_Response__fini(msg);
    return false;
  }
  return true;
}

void
rdk_ai_gateway_msg__srv__TextToText_Response__fini(rdk_ai_gateway_msg__srv__TextToText_Response * msg)
{
  if (!msg) {
    return;
  }
  // output
  rosidl_runtime_c__String__fini(&msg->output);
}

bool
rdk_ai_gateway_msg__srv__TextToText_Response__are_equal(const rdk_ai_gateway_msg__srv__TextToText_Response * lhs, const rdk_ai_gateway_msg__srv__TextToText_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->output), &(rhs->output)))
  {
    return false;
  }
  return true;
}

bool
rdk_ai_gateway_msg__srv__TextToText_Response__copy(
  const rdk_ai_gateway_msg__srv__TextToText_Response * input,
  rdk_ai_gateway_msg__srv__TextToText_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // output
  if (!rosidl_runtime_c__String__copy(
      &(input->output), &(output->output)))
  {
    return false;
  }
  return true;
}

rdk_ai_gateway_msg__srv__TextToText_Response *
rdk_ai_gateway_msg__srv__TextToText_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Response * msg = (rdk_ai_gateway_msg__srv__TextToText_Response *)allocator.allocate(sizeof(rdk_ai_gateway_msg__srv__TextToText_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rdk_ai_gateway_msg__srv__TextToText_Response));
  bool success = rdk_ai_gateway_msg__srv__TextToText_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rdk_ai_gateway_msg__srv__TextToText_Response__destroy(rdk_ai_gateway_msg__srv__TextToText_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rdk_ai_gateway_msg__srv__TextToText_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__init(rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Response * data = NULL;

  if (size) {
    data = (rdk_ai_gateway_msg__srv__TextToText_Response *)allocator.zero_allocate(size, sizeof(rdk_ai_gateway_msg__srv__TextToText_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rdk_ai_gateway_msg__srv__TextToText_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rdk_ai_gateway_msg__srv__TextToText_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__fini(rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rdk_ai_gateway_msg__srv__TextToText_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rdk_ai_gateway_msg__srv__TextToText_Response__Sequence *
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * array = (rdk_ai_gateway_msg__srv__TextToText_Response__Sequence *)allocator.allocate(sizeof(rdk_ai_gateway_msg__srv__TextToText_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__destroy(rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__are_equal(const rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * lhs, const rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rdk_ai_gateway_msg__srv__TextToText_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rdk_ai_gateway_msg__srv__TextToText_Response__Sequence__copy(
  const rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * input,
  rdk_ai_gateway_msg__srv__TextToText_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rdk_ai_gateway_msg__srv__TextToText_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rdk_ai_gateway_msg__srv__TextToText_Response * data =
      (rdk_ai_gateway_msg__srv__TextToText_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rdk_ai_gateway_msg__srv__TextToText_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rdk_ai_gateway_msg__srv__TextToText_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rdk_ai_gateway_msg__srv__TextToText_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
