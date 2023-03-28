cmake_minimum_required(VERSION 3.24)
project(Heap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Heap
        MinHeap.cpp
        MinHeap.h main.cpp)
