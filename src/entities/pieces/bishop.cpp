#include "entities/pieces/bishop.h"

Bishop::Bishop(const BasePiece::PieceColor color) : BasePiece(color) {

}

const std::vector<BasePiece::Location> Bishop::possible_moves(const Board& board) const {
    return check_diagonals(board);
}
