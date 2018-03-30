#include "entities/board.h"


const Board::BoardData& Board::at(const Location location) const {
    return _board[location.first][location.second];
}
