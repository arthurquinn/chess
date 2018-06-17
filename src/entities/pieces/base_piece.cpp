#include "entities/pieces/base_piece.h"
#include "entities/pieces/king.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"


using Location = BasePiece::Location;
using Color = BasePiece::Color;

Color BasePiece::adversarial_color(const Color color) {
    switch (color) {
    case Color::WHITE:
        return Color::BLACK;
    case Color::BLACK:
        return Color::WHITE;
    default:
        return Color::INVALID;
    }
}

bool BasePiece::can_move(const Board& board, const int rank, const int file) const {
    return board.in_bounds(rank, file) && ( board.empty(rank, file) || is_adversary(board.at(rank, file)) );
}

bool BasePiece::can_move(const Board& board, const Location& dest) const {
    return can_move(board, dest.first, dest.second);
}

std::vector<Location> BasePiece::check_path(const Board& board, const int dr, const int df) const {
    auto locs = std::vector<Location>();
    auto rank = _location.first + dr;
    auto file = _location.second + df;
    while (can_move(board, rank, file)) {
        locs.emplace_back(rank, file);

        // Can move is true; however this is a capture square...cannot move further on this path
        if (!board.empty(rank, file)) {
            break;
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

std::vector<Location> BasePiece::possible_moves(const Board& board) const {
    auto moves = possible_moves_no_check(board);
    STL_Helper::filter_vector(moves, [this, &board] (const auto& dest) {
        
        // Perform move
        auto simulation = board;
        simulation.move(_location, dest);

        // Check if any opponent pieces can capture allied king
        const auto& allied_king_loc = simulation.king_location(_color);
        const auto* const allied_king = dynamic_cast<const King* const>(&simulation.at(allied_king_loc));
        return allied_king->in_check(simulation);
    });
    return moves;
}
