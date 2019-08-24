cmake_minimum_required(VERSION 3.6)
project(fibonacci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gcc")

set(SOURCE_FILES main.c)
add_executable(fibonacci ${SOURCE_FILES})