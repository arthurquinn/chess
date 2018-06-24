#include "entities/pieces/pawn.h"
#include "entities/board.h"
#include "conceptual/moves/basic_move.h"
#include "conceptual/moves/capture_move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

std::vector<Location> Pawn::line_of_sight(const Board& board) const {
    std::vector<Location> locs;

    const auto& dr = move_direction();
    const auto& rank = _location.rank();
    const auto& file = _location.file();

    if ( board.in_bounds(rank + dr, file) && board.empty(rank + dr, file) ) {
        locs.emplace_back(rank + dr, file);
    }

    if ( !_was_moved && ( board.in_bounds(rank + dr * 2, file) && board.empty(rank + dr * 2, file) ) ) {
        locs.emplace_back(rank + dr *2, file);
    }

    for (const auto& df : { -1, 1 }) {
        const auto& attack_loc = Location(rank + dr, file + df);
        if (board.in_bounds(attack_loc) &&
                    board.occupied(attack_loc) &&
                    board.at(attack_loc).is_adversary(_color)) {

            locs.push_back(attack_loc);
        }
    }
    return locs;
}

void Pawn::print(std::ostream& os) const {
    common_print(os, 'p');
}

std::unique_ptr<Piece> Pawn::clone() const {
    return std::make_unique<Pawn>(*this);
}

void Pawn::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
