cmake_minimum_required(VERSION 3.29)
project(Assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "source/*.cpp"
)

add_executable(Assignment1 ${SOURCES}
        source/commandService/CommandFactoryRegistry.h
        source/services/FigureService.cpp
        source/model/colors/Color.h
        source/model/figure/Shape.h
        source/model/figure/Rectangle.cpp
        source/utils/Utils.h
        source/model/figure/Square.h
        source/model/figure/Shape.cpp)
target_include_directories(Assignment1 PRIVATE source)

