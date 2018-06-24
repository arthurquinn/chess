#include "entities/pieces/king.h"
#include "entities/board.h"
#include "conceptual/moves/basic_move.h"
#include "conceptual/moves/capture_move.h"
#include "helpers/stl_helper.h"
#include "interfaces/visitors/piece_visitor.h"

#include <algorithm>

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

using CastleState = King::CastleState;

std::vector<Location> King::line_of_sight(const Board& board) const {
    std::vector<Location> locs;
    const auto& d = { -1, 0, 1 };
    for (const auto& dr : d) {
        for (const auto& df : d) {
            if (dr == 0 && df == 0) continue;

            const auto& rank = _location.rank() + dr;
            const auto& file = _location.file() + df;
            if (can_move(board, rank, file)) {
                locs.emplace_back(rank, file);
            }
            else if (can_capture(board, rank, file)) {
                locs.emplace_back(rank, file);
            }
        }
    }
    return locs;
}

void King::print(std::ostream& os) const {
    common_print(os, 'k');
}

std::unique_ptr<Piece> King::clone() const {
    return std::make_unique<King>(*this);
}

void King::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}

// TODO: rename to castle_position()
CastleState King::castle_state() const {
    return _was_moved ? CastleState::CANNOT_CASTLE : CastleState::IN_POSITION;
}

bool King::in_check(const Board& board) const {
    return board.any([this, &board] (const auto& piece) {
        return piece.is_adversary(_color) && piece.in_line_of_sight(_location, board);
    });
}
