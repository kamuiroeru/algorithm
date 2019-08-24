cmake_minimum_required(VERSION 3.6)
project(ringbuffer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gcc")

set(SOURCE_FILES
    main.c)

add_executable(ringbuffer ${SOURCE_FILES})