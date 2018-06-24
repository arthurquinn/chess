#include "entities/pieces/base_piece.h"
#include "entities/pieces/king.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"
#include "visitors/castle_visitor.h"
#include "conceptual/moves/basic_move.h"
#include "conceptual/moves/capture_move.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

using Color = BasePiece::Color;

bool BasePiece::can_capture(const Board& board, const int rank, const int file) const {
    return board.in_bounds(rank, file) && is_adversary(board.at(rank, file));
}

bool BasePiece::can_capture(const Board& board, const Location& dest) const {
    return  can_capture(board, dest.rank(), dest.file());
}

bool BasePiece::can_move(const Board& board, const int rank, const int file) const {
    return board.in_bounds(rank, file) && board.empty(rank, file);
}

bool BasePiece::can_move(const Board& board, const Location& dest) const {
    return can_move(board, dest.rank(), dest.file());
}

std::vector<Location> BasePiece::check_path(const Board& board, const int dr, const int df) const {
    std::vector<Location> locs;
    auto rank = _location.rank() + dr;
    auto file = _location.file() + df;
    while (can_move(board, rank, file)) {
        locs.emplace_back(rank, file);

        rank += dr;
        file += df;
    }
    if (can_capture(board, rank, file)) {
        locs.emplace_back(rank, file);
    }
    return locs;
}

std::vector<Location> BasePiece::check_diagonals(const Board& board) const {
    std::vector<Location> locs;
    const auto& d = { 1, -1 };
    for (const auto& dr : d) {
        for (const auto& df : d) {
            STL_Helper::append_vectors(locs, check_path(board, dr, df));
        }
    }
    return locs;
}

std::vector<Location> BasePiece::check_across(const Board& board) const {
    std::vector<Location> locs;
    const auto& d = { 1, -1 };
    for (const auto& dr : d) {
        STL_Helper::append_vectors(locs, check_path(board, dr, 0));
    }
    for (const auto& df : d) {
        STL_Helper::append_vectors(locs, check_path(board, 0, df));
    }
    return locs;
}

vec_uptr<Move> BasePiece::legal_moves(const Board& board) const {
    const auto& locs = line_of_sight(board);

    vec_uptr<Move> moves;

    CastleVisitor castler(_color);
    board.visit_pieces(castler);

    // TODO: implement
    // STL_Helper::append_vectors(moves, castler.evaluate(board));

    return moves;
}

