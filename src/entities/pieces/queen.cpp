#include "entities/pieces/queen.h"

Queen::Queen(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {
    
}

const std::vector<BasePiece::Location> Queen::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_across(board, locs);
    check_diagonals(board, locs);
    return locs;
}

std::unique_ptr<BasePiece> Queen::clone() const {
    return std::make_unique<Queen>(_color, _location.first, _location.second);
}

void Queen::print(std::ostream& os) const {
    os << " q" << color_char() << " ";
}
