#include "gtest/gtest.h"

#include "entities/board.h"

int main(int argc, char **argv) {

    Board board;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
