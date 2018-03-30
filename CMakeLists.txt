cmake_minimum_required(VERSION 3.5.1)
project(chess)

include(CTest)

find_package(PkgConfig REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(chess "")

target_link_libraries(chess ${SDL2_LIBRARIES})
target_sources(chess 
    PRIVATE
        src/main.cpp
        src/factories/piece_factory.cpp
        src/graphics/window.cpp
        src/entities/board.cpp
        src/entities/player.cpp
        src/entities/pieces/base_piece.cpp
        src/entities/pieces/queen.cpp
        src/entities/pieces/king.cpp
        src/entities/pieces/pawn.cpp
        src/entities/pieces/knight.cpp
        src/entities/pieces/bishop.cpp
        src/entities/pieces/rook.cpp
)
target_compile_options(chess PUBLIC -std=c++14 -Wall -pedantic -g -DDEBUG)



# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

add_subdirectory(test)
