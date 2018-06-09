#include "entities/pieces/base_piece.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"

using Location = BasePiece::Location;

std::vector<Location> BasePiece::check_path(const Board& board, const int dr, const int df) const {
    auto locs = std::vector<Location>();
    auto rank = _location.first + dr;
    auto file = _location.second + df;
    while (board.in_bounds(rank, file)) {
        if (board.empty(rank, file)) {
            locs.emplace_back(rank, file);
        }
        rank += dr;
        file += df;
    }
    return locs;
}

std::vector<Location> BasePiece::check_diagonals(const Board& board) const {
    auto locs = std::vector<Location>();
    const auto& d = { 1, -1 };
    for (const auto& dr : d) {
        for (const auto& df : d) {
            STL_Helper::append_vectors(locs, check_path(board, dr, df));
        }
    }
    return locs;
}

std::vector<Location> BasePiece::check_across(const Board& board) const {
    auto locs = std::vector<Location>();
    const auto& d = { 1, -1 };
    for (const auto& dr : d) {
        STL_Helper::append_vectors(locs, check_path(board, dr, 0));
    }
    for (const auto& df : d) {
        STL_Helper::append_vectors(locs, check_path(board, 0, df));
    }
    return locs;
}
