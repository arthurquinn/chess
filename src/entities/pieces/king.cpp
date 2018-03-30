#include "entities/pieces/king.h"

King::King(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> King::possible_moves(const Board& board) const {
    return std::vector<Location>();
}
