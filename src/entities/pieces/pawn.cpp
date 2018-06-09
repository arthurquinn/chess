#include "entities/pieces/pawn.h"
#include "entities/board.h"

using Location = Pawn::Location;

std::vector<Location> Pawn::possible_moves(const Board& board) const {
    auto locs = std::vector<Location>();

    const auto& dr = move_direction();
    const auto& rank = _location.first;
    const auto& file = _location.second;

    if (can_move(board, rank + dr, file)) {
        locs.push_back(Location(rank + dr, file));
    }

    if (!_was_moved && can_move(board, rank + dr * 2, file)) {
        locs.push_back(Location(rank + dr * 2, file));
    }

    for (const auto& df : { -1, 1 }) {
        if (can_move(board, rank + dr, file + df)) {
            locs.push_back(Location(rank + dr, file + df));
        }
    }
    return locs;
}
