#include "entities/pieces/king.h"

#include "entities/board.h"

King::King(const BasePiece::PieceColor color, const int r, const int f) : BasePiece(color, r, f) {

}

const std::vector<BasePiece::Location> King::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    const auto d = { -1, 0, 1 };
    for (const auto dr : d) {
        for (const auto df : d) {
            if (dr == 0 && df == 0) continue;
            const int r = _location.first + dr;
            const int f = _location.second + df;
            if (board.in_bounds(r, f) && (board.empty(r, f) || opposing_colors(board.at(r, f)))) {
                locs.push_back(Location(r, f));
            }
        }
    }
    return locs;
}

std::unique_ptr<BasePiece> King::clone() const {
    return std::make_unique<King>(_color, _location.first, _location.second);
}

void King::print(std::ostream& os) const {
    os << " k" << color_char() << " ";
}
