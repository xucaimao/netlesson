cmake_minimum_required(VERSION 3.8)
project(reverselink)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(reverselink ${SOURCE_FILES})