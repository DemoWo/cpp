cmake_minimum_required(VERSION 3.21)
project(MovieDataAnalysis)

set(CMAKE_CXX_STANDARD 23)
set(JSON_Install OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(MovieDataAnalysis main.cpp)

target_link_libraries(MovieDataAnalysis PRIVATE nlohmann_json::nlohmann_json)