cmake_minimum_required(VERSION 3.20)
project(Week2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Week2
        lab2/Sort.cpp
        lab2/Sort.h lab2/main.cpp)
