#include "entities/pieces/rook.h"
#include "entities/board.h"

using Location = Rook::Location;

std::vector<Location> Rook::possible_moves(const Board& board) const {
    return check_across(board);
}
