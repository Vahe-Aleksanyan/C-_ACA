cmake_minimum_required(VERSION 3.14)
project(iterator)

set(CMAKE_CXX_STANDARD 17)

add_executable(iterator main.cpp Iterator.h queue.h queue.cpp Iterator.cpp)

