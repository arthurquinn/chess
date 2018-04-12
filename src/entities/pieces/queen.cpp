#include "entities/pieces/queen.h"

Queen::Queen(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Queen::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_across(board, locs);
    check_diagonals(board, locs);
    return locs;
}

void Queen::print(std::ostream& os) const {
    os << " q" << color_char() << " ";
}
