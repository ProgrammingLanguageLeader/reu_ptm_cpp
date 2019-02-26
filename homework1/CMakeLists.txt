cmake_minimum_required(VERSION 3.13)
project(homework1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework1
        Doctor.cpp
        Doctor.h
        Game.cpp
        Game.h
        Grandmother.cpp
        Grandmother.h
        Human.cpp
        Human.h
        main.cpp
        Musician.cpp
        Musician.h)
