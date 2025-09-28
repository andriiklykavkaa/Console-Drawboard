cmake_minimum_required(VERSION 3.29)
project(Assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "source/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "source/*.h")

add_executable(Assignment1 ${SOURCE_FILES} ${HEADER_FILES})

find_package(nlohmann_json REQUIRED)

target_include_directories(Assignment1 PRIVATE source)
target_link_libraries(Assignment1 PRIVATE nlohmann_json::nlohmann_json)


message("Triangle.h")
