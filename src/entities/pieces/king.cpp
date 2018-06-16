#include "entities/pieces/king.h"
#include "entities/board.h"

using Location = King::Location;

std::vector<Location> King::possible_moves(const Board& board) const {
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

void King::print(std::ostream& os) const {
    common_print(os, 'k');
}
