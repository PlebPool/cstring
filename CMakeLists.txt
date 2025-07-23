cmake_minimum_required(VERSION 3.31)
project(cstring C)

set(CMAKE_C_STANDARD 99)

add_library(cstring STATIC library.c
        )
