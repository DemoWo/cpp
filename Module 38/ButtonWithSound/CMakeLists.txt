cmake_minimum_required(VERSION 3.21)
project(ButtonWithSound)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/QT/6.5.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(ButtonWithSound
        src.qrc
        src/settings.h
        src/settings.cpp
        main.cpp
)
target_link_libraries(ButtonWithSound
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        )
