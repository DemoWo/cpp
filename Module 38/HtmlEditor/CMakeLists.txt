cmake_minimum_required(VERSION 3.21)
project(HtmlEditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/QT/5.15.2/mingw_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
        REQUIRED)

add_executable(HtmlEditor
        src.qrc
        htmleditor.h
        htmleditor.cpp
        main.cpp
)
target_link_libraries(HtmlEditor
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebEngineWidgets
        )
