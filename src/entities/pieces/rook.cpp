#include "entities/pieces/rook.h"

Rook::Rook(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Rook::possible_moves(const Board& board) const {
    return std::vector<Location>();
}
