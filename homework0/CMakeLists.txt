cmake_minimum_required(VERSION 3.13)
project(homework0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework0
        AbstractBaseWorker.cpp
        AbstractBaseWorker.h
        Car.cpp
        Car.h
        CarShowroom.cpp
        CarShowroom.h
        CommonWorker.cpp
        CommonWorker.h
        main.cpp
        Salesman.cpp
        Salesman.h)
