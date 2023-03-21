cmake_minimum_required(VERSION 3.16)
project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV CONFIG REQUIRED)

add_executable(a main.cpp)
target_link_libraries(a PRIVATE opencv_highgui opencv_core)

