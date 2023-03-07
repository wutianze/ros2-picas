# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_picas_example_mt_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED picas_example_mt_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(picas_example_mt_FOUND FALSE)
  elseif(NOT picas_example_mt_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(picas_example_mt_FOUND FALSE)
  endif()
  return()
endif()
set(_picas_example_mt_CONFIG_INCLUDED TRUE)

# output package information
if(NOT picas_example_mt_FIND_QUIETLY)
  message(STATUS "Found picas_example_mt: 0.0.0 (${picas_example_mt_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'picas_example_mt' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${picas_example_mt_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(picas_example_mt_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${picas_example_mt_DIR}/${_extra}")
endforeach()