cmake_minimum_required(VERSION 3.24)
project(painterPoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(painterPoint main.cpp)

add_library(Lib MainWindow.cpp Board.cpp Shapes/Shape.cpp Shapes/Circle.cpp Shapes/Square.cpp
        Shapes/Rectangular.cpp Shapes/Rectangular.cpp #[[Values.h]] Shapes/Polygon.cpp Shapes/Star.cpp
        Shapes/Ellipse.cpp Shapes/Triangular.cpp Shapes/Random.cpp Shapes/Painter.cpp)


target_link_libraries(Lib
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )


target_link_libraries(painterPoint
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Lib
        )
