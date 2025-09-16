cmake_minimum_required(VERSION 3.29)
project(Assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "source/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "source/*.h")

add_executable(Assignment1 ${SOURCE_FILES} ${HEADER_FILES}
        source/model/commandFactory/SelectFactory.h)
target_include_directories(Assignment1 PRIVATE source)


message("Circle.h")
