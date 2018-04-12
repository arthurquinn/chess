#include "entities/pieces/knight.h"
#include "entities/board.h"


Knight::Knight(const BasePiece::PieceColor color) :
        BasePiece(color),
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
        const auto x = _location.first + l.first;
        const auto y = _location.second + l.second;
        if (in_bounds(x, y) && !board.at(x, y)) {
            locs.push_back(Location(x, y));
        }
    }
    return std::vector<Location>();
}

void Knight::print(std::ostream& os) const {
    os << " n" << color_char() << " ";
}

