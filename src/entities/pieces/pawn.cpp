#include "entities/pieces/pawn.h"
#include "entities/board.h"

using Location = Pawn::Location;

std::vector<Location> Pawn::possible_moves_no_check(const Board& board) const {
    auto locs = std::vector<Location>();

    const auto& dr = move_direction();
    const auto& rank = _location.first;
    const auto& file = _location.second;

    if (can_move(board, rank + dr, file)) {
        locs.emplace_back(rank + dr, file);
    }

    if (!_was_moved && can_move(board, rank + dr * 2, file)) {
        locs.emplace_back(rank + dr * 2, file);
    }

    for (const auto& df : { -1, 1 }) {
        const auto& attack_loc = Location(rank + dr, file + df);
        if (board.in_bounds(attack_loc) &&
                    board.occupied(attack_loc) &&
                    board.at(attack_loc).is_adversary(_color)) {
            locs.emplace_back(attack_loc);
        }
    }
    return locs;
}

void Pawn::print(std::ostream& os) const {
    common_print(os, 'p');
}

std::unique_ptr<BasePiece> Pawn::clone() const {
    return std::make_unique<Pawn>(*this);
}
