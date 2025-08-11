cmake_minimum_required(VERSION 3.25)
project(cstring C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_library(cstring STATIC library.c
        src/cstring.c
)

target_include_directories(cstring PUBLIC include)
