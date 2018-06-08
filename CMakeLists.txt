cmake_minimum_required(VERSION 3.5.1)
project(chess)

find_package(PkgConfig REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(chess "")

target_link_libraries(chess ${SDL2_LIBRARIES})
target_sources(chess 
    PRIVATE
        src/main.cpp
)
target_compile_options(chess PUBLIC -std=c++14 -Wall -g -DDEBUG)
