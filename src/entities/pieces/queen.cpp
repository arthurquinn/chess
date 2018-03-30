#include "entities/pieces/queen.h"

Queen::Queen(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Queen::possible_moves(const Board& board) const {
    return std::vector<Location>();
}

