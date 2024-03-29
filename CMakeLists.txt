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
        src/algorithms/chess.cpp
        src/commands/move_piece.cpp
        src/commands/possible_moves.cpp
        src/conceptual/location.cpp
        src/conceptual/moves/basic_move.cpp
        src/conceptual/moves/capture_move.cpp
        src/conceptual/moves/castle_move.cpp
        src/entities/board.cpp
        src/entities/game.cpp
        src/entities/pieces/base_piece.cpp
        src/entities/pieces/bishop.cpp
        src/entities/pieces/king.cpp
        src/entities/pieces/knight.cpp
        src/entities/pieces/pawn.cpp
        src/entities/pieces/queen.cpp
        src/entities/pieces/rook.cpp
        src/io/keyboard.cpp
        src/io/logger.cpp
        src/visitors/castle_visitor.cpp
        src/visitors/in_check_visitor.cpp
)
target_compile_options(chess PUBLIC -std=c++14 -Wall -Wextra -g -O0 -DDEBUG)
