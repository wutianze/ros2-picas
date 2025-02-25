// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from picas_msgs:msg/UTime.idl
// generated code does not contain a copyright notice
#include "picas_msgs/msg/detail/u_time__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
picas_msgs__msg__UTime__init(picas_msgs__msg__UTime * msg)
{
  if (!msg) {
    return false;
  }
  // sec
  // usec
  return true;
}

void
picas_msgs__msg__UTime__fini(picas_msgs__msg__UTime * msg)
{
  if (!msg) {
    return;
  }
  // sec
  // usec
}

bool
picas_msgs__msg__UTime__are_equal(const picas_msgs__msg__UTime * lhs, const picas_msgs__msg__UTime * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sec
  if (lhs->sec != rhs->sec) {
    return false;
  }
  // usec
  if (lhs->usec != rhs->usec) {
    return false;
  }
  return true;
}

bool
picas_msgs__msg__UTime__copy(
  const picas_msgs__msg__UTime * input,
  picas_msgs__msg__UTime * output)
{
  if (!input || !output) {
    return false;
  }
  // sec
  output->sec = input->sec;
  // usec
  output->usec = input->usec;
  return true;
}

picas_msgs__msg__UTime *
picas_msgs__msg__UTime__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  picas_msgs__msg__UTime * msg = (picas_msgs__msg__UTime *)allocator.allocate(sizeof(picas_msgs__msg__UTime), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(picas_msgs__msg__UTime));
  bool success = picas_msgs__msg__UTime__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
picas_msgs__msg__UTime__destroy(picas_msgs__msg__UTime * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    picas_msgs__msg__UTime__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
picas_msgs__msg__UTime__Sequence__init(picas_msgs__msg__UTime__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  picas_msgs__msg__UTime * data = NULL;

  if (size) {
    data = (picas_msgs__msg__UTime *)allocator.zero_allocate(size, sizeof(picas_msgs__msg__UTime), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = picas_msgs__msg__UTime__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        picas_msgs__msg__UTime__fini(&data[i - 1]);
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
picas_msgs__msg__UTime__Sequence__fini(picas_msgs__msg__UTime__Sequence * array)
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
      picas_msgs__msg__UTime__fini(&array->data[i]);
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

picas_msgs__msg__UTime__Sequence *
picas_msgs__msg__UTime__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  picas_msgs__msg__UTime__Sequence * array = (picas_msgs__msg__UTime__Sequence *)allocator.allocate(sizeof(picas_msgs__msg__UTime__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = picas_msgs__msg__UTime__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
picas_msgs__msg__UTime__Sequence__destroy(picas_msgs__msg__UTime__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    picas_msgs__msg__UTime__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
picas_msgs__msg__UTime__Sequence__are_equal(const picas_msgs__msg__UTime__Sequence * lhs, const picas_msgs__msg__UTime__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!picas_msgs__msg__UTime__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
picas_msgs__msg__UTime__Sequence__copy(
  const picas_msgs__msg__UTime__Sequence * input,
  picas_msgs__msg__UTime__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(picas_msgs__msg__UTime);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    picas_msgs__msg__UTime * data =
      (picas_msgs__msg__UTime *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!picas_msgs__msg__UTime__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          picas_msgs__msg__UTime__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!picas_msgs__msg__UTime__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
