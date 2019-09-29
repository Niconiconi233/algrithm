cmake_minimum_required(VERSION 2.8)

project(test)

add_executable(main offer_31.cpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
add_definitions("-Wall -g")
