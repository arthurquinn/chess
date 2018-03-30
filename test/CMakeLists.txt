cmake_minimum_required(VERSION 3.5.1)
project(chess)

add_executable(test_chess "")

target_link_libraries(test_chess gtest_main)
add_test(NAME run_chess_test COMMAND test_chess)

target_sources(test_chess
    PRIVATE
        src/test_main
)
