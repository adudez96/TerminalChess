cmake_minimum_required(VERSION 3.0.2)

include_directories("${CMAKE_SOURCE_DIR}")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror -Wextra -Wconversion" )

add_executable(chess main.cpp Location.cpp)
