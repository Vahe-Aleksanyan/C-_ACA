cmake_minimum_required(VERSION 3.24)
project(learning)

set(CMAKE_CXX_STANDARD 14)

include_directories(basic_oop)

add_executable(learning
        basic_oop/dtime.cpp
        basic_oop/dtime.h
        basic_oop/emloyee.cpp
        basic_oop/employee.h
        basic_oop/hourlyemployee.cpp
        basic_oop/hourlyemployee.h
        basic_oop/main.cpp
        basic_oop/main2.cpp
        basic_oop/salariedemployee.cpp
        basic_oop/salariedemployee.h)
