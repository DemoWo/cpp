cmake_minimum_required(VERSION 3.21)
project(QueriesWithArguments)

set(CMAKE_CXX_STANDARD 23)

set (BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

add_executable(QueriesWithArguments main.cpp)
target_link_libraries(QueriesWithArguments PRIVATE cpr::cpr)