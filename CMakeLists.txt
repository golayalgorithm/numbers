cmake_minimum_required (VERSION 2.6)
project (Numbers)

set (Numbers_VERSION_MAJOR 1)
set (Numbers_VERSION_MINOR 0)
set (CMAKE_CXX_FLAGS "-std=c++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/NumbersConfig.h.in"
  "${PROJECT_BINARY_DIR}/NumbersConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_subdirectory(src)
