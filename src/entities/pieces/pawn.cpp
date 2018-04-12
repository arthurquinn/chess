#include "entities/pieces/pawn.h"
#include "entities/board.h"

Pawn::Pawn(const BasePiece::PieceColor color) :
        BasePiece(color),
        _was_moved(false) {
    
}

const std::vector<BasePiece::Location> Pawn::possible_moves(const Board& board) const {
    auto locs =  std::vector<Location>();
    const auto dy = _color == PieceColor::WHITE ? 1 : -1;
    const auto x = _location.first;
    const auto y = _location.second + dy;
    if (in_bounds(x, y) && !board.at(x, y)) {
        locs.push_back(Location(x, y));
    }

    // First move check
    const auto y2 = y + dy;
    if (!_was_moved && in_bounds(x, y2) && !board.at(x, y2)) {
        locs.push_back(Location(x, y2));
    }
    return locs;
}

void Pawn::print(std::ostream& os) const {
    os << " p" << color_char() << " ";
}

