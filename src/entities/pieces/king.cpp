#include "entities/pieces/king.h"
#include "entities/board.h"
#include "conceptual/moves/basic_move.h"
#include "helpers/stl_helper.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

using CastleState = King::CastleState;

vec_uptr<Move> King::possible_moves_no_check(const Board& board) const {
    vec_uptr<Move> moves;
    const auto& d = { -1, 0, 1 };
    for (const auto& dr : d) {
        for (const auto& df : d) {
            if (dr == 0 && df == 0) continue;

            const auto& rank = _location.rank() + dr;
            const auto& file = _location.file() + df;
            if (can_move(board, rank, file)) {
                moves.push_back(std::make_unique<BasicMove>(_color, _location, Location(rank, file)));
            }
        }
    }
    return moves;
}

// TODO: fixme
// bool King::in_check(const Board& board) const {
//     const auto& adv_locs = board.piece_locations(adversarial_color(_color));
//     for (const auto& loc : adv_locs) {
//         const auto& adv_moves = board.at(loc).possible_moves_no_check(board);
//         if (STL_Helper::vector_contains(adv_moves, _location)) {
//             return true;
//         }
//     }
//     return false;
// }

void King::print(std::ostream& os) const {
    common_print(os, 'k');
}

std::unique_ptr<Piece> King::clone() const {
    return std::make_unique<King>(*this);
}

CastleState King::castle_state() const {
    return _was_moved ? CastleState::CANNOT_CASTLE : CastleState::CAN_CASTLE;
}

void King::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
