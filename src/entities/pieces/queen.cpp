#include "entities/pieces/queen.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"

using Location = Queen::Location;

std::vector<Location> Queen::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    STL_Helper::append_vectors(locs, check_across(board));
    STL_Helper::append_vectors(locs, check_diagonals(board));
    return locs;
}
