#include "entities/pieces/rook.h"

Rook::Rook(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {
    
}

const std::vector<BasePiece::Location> Rook::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_across(board, locs);
    return locs;
}

void Rook::print(std::ostream& os) const {
    os << " r" << color_char() << " ";
}
