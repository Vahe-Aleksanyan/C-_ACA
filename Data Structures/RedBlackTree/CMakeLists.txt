cmake_minimum_required(VERSION 3.24)
project(RedBlackTree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RedBlackTree
        RedBlackTree.cpp
        RedBlackTree.h main.cpp)
