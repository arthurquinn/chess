#include "entities/pieces/knight.h"
#include "entities/board.h"

using Location = Knight::Location;

const std::array<std::pair<int, int>, 8> Knight::L_MOVES = {
    std::make_pair( 1,  2),
    std::make_pair( 1, -2),
    std::make_pair(-1,  2),
    std::make_pair(-1, -2),
    std::make_pair( 2,  1),
    std::make_pair( 2, -1),
    std::make_pair(-2,  1),
    std::make_pair(-2, -1)
};

std::vector<Location> Knight::possible_moves_no_check(const Board& board) const {
    auto locs = std::vector<Location>();
    for (const auto& l : L_MOVES) {
        const auto& rank = _location.first + l.first;
        const auto& file = _location.second + l.second;
        if (board.in_bounds(rank, file) && board.empty(rank, file)) {
            locs.emplace_back(rank, file);
        }
    }
    return locs;
}

void Knight::print(std::ostream& os) const {
    common_print(os, 'n');
}

std::unique_ptr<BasePiece> Knight::clone() const {
    return std::make_unique<Knight>(*this);
}

