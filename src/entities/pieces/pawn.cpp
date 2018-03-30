#include "entities/pieces/pawn.h"

Pawn::Pawn(const BasePiece::PieceColor color) : BasePiece(color) {
    
}

const std::vector<BasePiece::Location> Pawn::possible_moves(const Board& board) const {
    return std::vector<Location>();
}

