cmake_minimum_required(VERSION 3.3)
project(ClionTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Card.cpp Card.h)
add_executable(ClionTest ${SOURCE_FILES})