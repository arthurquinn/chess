#include "entities/pieces/knight.h"

Knight::Knight(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Knight::possible_moves(const Board& board) const {
    return std::vector<Location>();
}
