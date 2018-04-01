#include "entities/pieces/rook.h"

Rook::Rook(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Rook::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_across(board, locs);
    return locs;
}
