cmake_minimum_required(VERSION 3.13)
project(homework2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework2
        BlackTea.h
        ChocolateCondiment.h
        Espresso.h
        GreenTea.h
        IBeverage.h
        ICondimentsDecoratorBase.h
        main.cpp
        MilkCondiment.h
        SugarCondiment.h)
