#include "entities/pieces/knight.h"
#include "entities/board.h"


Knight::Knight(const BasePiece::PieceColor color, const int r, const int f) :
        BasePiece(color, r, f),
        L_MOVES({
            {  1,  2 },
            {  1, -2 },
            { -1,  2 },
            { -1, -2 },
            {  2,  1 },
            {  2, -1 },
            { -2,  1 },
            { -2, -1 }
        }) {
    
}

const std::vector<BasePiece::Location> Knight::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    for (const auto& l : L_MOVES) {
        const auto r = _location.first + l.first;
        const auto f = _location.second + l.second;
        if (board.in_bounds(r, f) && (board.empty(r, f) || opposing_colors(board.at(r, f)))) {
            locs.push_back(Location(r, f));
        }
    }
    return locs;
}

std::shared_ptr<BasePiece> Knight::clone() const {
    return std::make_shared<Knight>(_color, _location.first, _location.second);
}

void Knight::print(std::ostream& os) const {
    os << " n" << color_char() << " ";
}

