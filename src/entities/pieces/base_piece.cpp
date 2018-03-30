#include "entities/pieces/base_piece.h"
#include "entities/board.h"

BasePiece::BasePiece(const PieceColor color) : _color(color) {
    
}

const bool BasePiece::in_bounds(const int x, const int y) const {
    return x - Board::BOARD_DIM < 0 && y - Board::BOARD_DIM < 0;
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
