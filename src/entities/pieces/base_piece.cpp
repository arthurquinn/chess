#include "entities/pieces/base_piece.h"
#include "entities/board.h"

BasePiece::BasePiece(const PieceColor color, const int r, const int f) :
        _color(color),
        _location(r, f) {

}

char BasePiece::color_char() const {
    return _color == PieceColor::WHITE ? 'w' : 'b';
}

bool BasePiece::opposing_colors(const std::unique_ptr<BasePiece>& other) const {
    return other != nullptr && other->_color != _color;
}

void BasePiece::move(const int r, const int f) {
    _location.first = r;
    _location.second = f;
}

void BasePiece::check_path(const Board& board, std::vector<Location>& locs, int r, int f, const int dr, const int df) const {
    r += dr;
    f += df;
    while (board.in_bounds(r, f)) {
        if (board.empty(r, f)) {
            locs.push_back(Location(r, f));
            r += dr;
            f += df;
        } else if (opposing_colors(board.at(r, f))) {
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
