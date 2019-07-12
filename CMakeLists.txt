cmake_minimum_required(VERSION 2.8)

project(test)

add_executable(main Base64.h Base64.cpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_definitions("-Wall -g")