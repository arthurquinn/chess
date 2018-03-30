cmake_minimum_required(VERSION 3.5.1)
project(chess)

add_executable(test_chess "")

target_link_libraries(test_chess gtest_main)

enable_testing()
add_test(NAME run_chess_test COMMAND test_chess)

target_compile_options(test_chess PUBLIC -std=c++14 -Wall -pedantic -g -DDEBUG)
target_sources(test_chess
    PRIVATE
        src/test_main
)
