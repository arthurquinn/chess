#include "entities/pieces/bishop.h"

Bishop::Bishop(const BasePiece::PieceColor color) : BasePiece(color) {

}

const std::vector<BasePiece::Location> Bishop::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_diagonals(board, locs);
    return locs;
}

void Bishop::print(std::ostream& os) const {
    os << " b" << color_char() << " ";
}
