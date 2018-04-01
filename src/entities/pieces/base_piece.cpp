#include "entities/pieces/base_piece.h"
#include "entities/board.h"

BasePiece::BasePiece(const PieceColor color) : _color(color) {
    
}

const bool BasePiece::in_bounds(const int x, const int y) const {
    return x - Board::BOARD_DIM < 0 && y - Board::BOARD_DIM < 0;
}

void BasePiece::check_path(const Board& board, std::vector<Location>& locs, int x, int y, const int dx, const int dy) const {
    x += dx;
    y += dy;
    while (in_bounds(x, y)) {
        if (!board.at(x, y)) {
            locs.push_back(Location(x, y));
            x += dx;
            y += dy;
        } else {
            break;
        }
    }
}

void BasePiece::check_diagonals(const Board& board, std::vector<Location>& locs) const {
    const auto d = { 1, -1 };
    for (const auto dx : d) {
        for (const auto dy : d) {
            check_path(board, locs, _location.first, _location.second, dx, dy);
        }
    }
}

void BasePiece::check_across(const Board& board, std::vector<Location>& locs) const {
    const auto d = { -1 , 1 };
    for (const auto dx : d) {
        check_path(board, locs, _location.first, _location.second, dx, 0);
    }
    for (const auto dy : d) {
        check_path(board, locs, _location.first, _location.second, 0, dy);
    }
}