#include "entities/pieces/pawn.h"
#include "entities/board.h"

using super = BasePiece;

Pawn::Pawn(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {
    
}

void Pawn::move(const int r, const int f) {
    super::move(r, f);
    _was_moved = true;
}

const std::vector<BasePiece::Location> Pawn::possible_moves(const Board& board) const {
    auto locs =  std::vector<Location>();
    const auto dr = _color == PieceColor::WHITE ? 1 : -1;
    const auto rank = _location.first + dr;
    const auto file = _location.second;
    if (board.in_bounds(rank, file) && board.empty(rank, file)) {
        locs.push_back(Location(rank, file));
    }

    // First move check
    const auto rank2 = rank + dr;
    if (!_was_moved && board.in_bounds(rank2, file) && board.empty(rank, file)) {
        locs.push_back(Location(rank2, file));
    }

    // Diagonal capture check
    for (const auto df : { -1, 1 }) {
        const auto file2 = file + df;
        if (board.in_bounds(rank, file2) && opposing_colors(board.at(rank, file2))) {
            locs.push_back(Location(rank, file2));
        }
    }
    return locs;
}

std::shared_ptr<BasePiece> Pawn::clone() const {
    auto p = std::make_shared<Pawn>(_color, _location.first, _location.second);
    p->_was_moved = _was_moved;
    return p;
}

void Pawn::print(std::ostream& os) const {
    os << " p" << color_char() << " ";
}

