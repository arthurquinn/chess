#include "entities/board.h"

const Board::BoardData& Board::at(const int x, const int y) const {
    return _board[x][y];
}

const Board::BoardData& Board::at(const Location location) const {
    return at(location.first, location.second);
}
