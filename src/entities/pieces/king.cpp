#include "entities/pieces/king.h"

#include "entities/board.h"

King::King(const BasePiece::PieceColor color) : BasePiece(color) {

}

const std::vector<BasePiece::Location> King::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();
    const auto d = { -1, 0, 1 };
    for (const auto dx : d) {
        for (const auto dy : d) {
            if (dx == 0 && dy == 0) continue;
            const int x = _location.first + dx;
            const int y = _location.second + dy;
            if (!board.at(x, y)) {
                locs.push_back(Location(x, y));
            }
        }
    }
    return std::vector<Location>();
}
