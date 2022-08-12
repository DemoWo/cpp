cmake_minimum_required(VERSION 3.21)

set(MY_Include_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(myTask main.cpp ${MY_Include_DIR}/operation.h)

target_include_directories(myTask PUBLIC ${MY_Include_DIR})