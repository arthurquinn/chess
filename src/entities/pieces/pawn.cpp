#include "entities/pieces/pawn.h"
#include "entities/board.h"

Pawn::Pawn(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {
    
}

const std::vector<BasePiece::Location> Pawn::possible_moves(const Board& board) const {
    auto locs =  std::vector<Location>();
    const auto dr = _color == PieceColor::WHITE ? 1 : -1;
    const auto rank = _location.first + dr;
    const auto file = _location.second;
    if (in_bounds(rank, file) && !board.at(rank, file)) {
        locs.push_back(Location(rank, file));
    }

    // First move check
    const auto rank2 = rank + dr;
    if (!_was_moved && in_bounds(rank2, file)) {
        locs.push_back(Location(rank2, file));
    }
    return locs;
}

void Pawn::print(std::ostream& os) const {
    os << " p" << color_char() << " ";
}

