cmake_minimum_required(VERSION 3.24)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue
        QueueWIthSLL.cpp dequeWIthArray.cpp CircularQueue.cpp)
