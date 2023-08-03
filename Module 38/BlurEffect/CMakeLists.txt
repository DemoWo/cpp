cmake_minimum_required(VERSION 3.21)
project(BlurEffect)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/QT/5.15.2/mingw_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(BlurEffect
        src.qrc
        imageblurer.h
        imageblurer.cpp
        main.cpp
)
target_link_libraries(BlurEffect
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
