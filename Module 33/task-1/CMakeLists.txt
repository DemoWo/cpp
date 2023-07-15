cmake_minimum_required(VERSION 3.21)
project(task_1)

set(CMAKE_CXX_STANDARD 23)

set(Boost_INCLUDE_DIR "C:\\boost_1_82_0\\boost_1_82_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_82_0\\boost_1_82_0\\stage\\lib")

find_package(Boost COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(task_1 main.cpp)
target_link_libraries(task_1 ${Boost_LIBRARIES})

if (MINGW)
    target_link_libraries(task_1 ws2_32)
endif ()