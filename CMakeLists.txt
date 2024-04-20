cmake_minimum_required(VERSION 3.27)
project(DataFrame_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DataFrame_Project
        functions.c
        functions.h
        main.c
        column.h
        cdataframe.h
        column.c
        test.c
        test.c
        cdataframe.c)
