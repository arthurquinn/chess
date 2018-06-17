#include "entities/pieces/king.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"

using Location = King::Location;

std::vector<Location> King::possible_moves_no_check(const Board& board) const {
    auto locs = std::vector<Location>();
    const auto& d = { -1, 0, 1 };
    for (const auto& dr : d) {
        for (const auto& df : d) {
            if (dr == 0 && df == 0) continue;

            const auto& rank = _location.first + dr;
            const auto& file = _location.second + df;
            if (board.in_bounds(rank, file) && board.empty(rank, file)) {
                locs.emplace_back(rank, file);
            }
        }
    }
    return locs;
}

bool King::in_check(const Board& board) const {
    const auto& adv_locs = board.piece_locations(adversarial_color(_color));
    for (const auto& loc : adv_locs) {
        const auto& adv_moves = board.at(loc).possible_moves_no_check(board);
        if (STL_Helper::vector_contains(adv_moves, _location)) {
            return true;
        }
    }
    return false;
}

void King::print(std::ostream& os) const {
    common_print(os, 'k');
}

std::unique_ptr<BasePiece> King::clone() const {
    return std::make_unique<King>(*this);
}
