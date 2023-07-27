cmake_minimum_required (VERSION 3.8)
project (DistanceToSegment)

add_executable (DistanceToSegment src/main.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DistanceToSegment PROPERTY CXX_STANDARD 20)
endif()
