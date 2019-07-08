cmake_minimum_required(VERSION 2.8)

project(test)

add_executable(main huffman.cc min_heap.hpp insertionSort.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")