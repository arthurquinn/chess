#include "entities/pieces/base_piece.h"
#include "entities/board.h"

BasePiece::BasePiece(const PieceColor color, const int r, const int f) :
        _color(color),
        _location(r, f) {

}

bool BasePiece::in_bounds(const int r, const int f) const {
    return r - Board::BOARD_DIM < 0 && f - Board::BOARD_DIM < 0;
}

void BasePiece::move(const int r, const int f) {
    _location.first = r;
    _location.second = f;
}

void BasePiece::check_path(const Board& board, std::vector<Location>& locs, int r, int f, const int dr, const int df) const {
    r += dr;
    f += df;
    while (in_bounds(r, f)) {
        if (!board.at(r, f)) {
            locs.push_back(Location(r, f));
            r += dr;
            f += df;
        } else if (opposing_colors(*board.at(r, f))) {
            locs.push_back(Location(r, f));
            break;
        } else {
            break;
        }
    }
}

void BasePiece::check_diagonals(const Board& board, std::vector<Location>& locs) const {
    const auto d = { 1, -1 };
    for (const auto dr : d) {
        for (const auto df : d) {
            check_path(board, locs, _location.first, _location.second, dr, df);
        }
    }
}

void BasePiece::check_across(const Board& board, std::vector<Location>& locs) const {
    const auto d = { -1 , 1 };
    for (const auto dr : d) {
        check_path(board, locs, _location.first, _location.second, dr, 0);
    }
    for (const auto df : d) {
        check_path(board, locs, _location.first, _location.second, 0, df);
    }
}
