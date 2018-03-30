#include "entities/pieces/base_piece.h"

BasePiece::BasePiece(const PieceColor color) : _color(color) {
    
}

const std::vector<BasePiece::Location> BasePiece::check_diagonals(const Board& board) const {
    auto ret = std::vector<Location>();
    auto d = { 1, -1 };
    for (auto dx : d) {
        for (auto dy : d) {
            int x = _location.first + dx;
            int y = _location.second + dy;
            while (in_bounds(x, y)) {
                if (!board.at(x, y)) {
                    ret.push_back(Location(x, y));
                    x += dx;
                    y += dy;
                } else {
                    break;
                }
            }
        }
    }
    return ret;
}
