# CMakeList.txt : CMake project for RomanToInt, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("RomanToInt")

# Add source to this project's executable.
add_executable (RomanToInt "RomanToInt.cpp" "RomanToInt.h" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RomanToInt PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
