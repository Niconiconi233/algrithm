cmake_minimum_required(VERSION 2.8)

project(test)

add_executable(main huffman.cc min_heap.hpp insertionSort.h bubble_sort.h bucket_sort.h list.hpp max_heap.hpp merge_sort.hpp queue.hpp quick_sort.h rb_tree.hpp search_tree.hpp stack.hpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")