cmake_minimum_required(VERSION 3.6)
project(heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main2.c)
add_executable(heap ${SOURCE_FILES})