cmake_minimum_required(VERSION 3.21)
project(InformationAboutTheFilmFromTheFilmPortal)

set(CMAKE_CXX_STANDARD 23)

set(JSON_Install OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(InformationAboutTheFilmFromTheFilmPortal main.cpp)

target_link_libraries(InformationAboutTheFilmFromTheFilmPortal PRIVATE nlohmann_json::nlohmann_json)