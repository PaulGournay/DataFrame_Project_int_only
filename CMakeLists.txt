cmake_minimum_required(VERSION 3.27)
project(DataFrame_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DataFrame_Project
        main.c
        column.h
        cdataframe.h
        column.c
        cdataframe.c)
