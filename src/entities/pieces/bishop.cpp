#include "entities/pieces/bishop.h"
#include "entities/board.h"

using Location = Bishop::Location;

std::vector<Location> Bishop::possible_moves(const Board& board) const {
    return check_diagonals(board);
}

void Bishop::print(std::ostream& os) const {
    common_print(os, 'b');
}
