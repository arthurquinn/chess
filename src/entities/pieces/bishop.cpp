#include "entities/pieces/bishop.h"

Bishop::Bishop(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {

}

const std::vector<BasePiece::Location> Bishop::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    check_diagonals(board, locs);
    return locs;
}

std::shared_ptr<BasePiece> Bishop::clone() const {
    return std::make_shared<Bishop>(_color, _location.first, _location.second);
}

void Bishop::print(std::ostream& os) const {
    os << " b" << color_char() << " ";
}
