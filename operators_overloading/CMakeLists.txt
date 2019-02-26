cmake_minimum_required(VERSION 3.13)
project(operators_overloading)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(operators_overloading
        main.cpp
        Money.h)
