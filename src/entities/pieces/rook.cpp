#include "entities/pieces/rook.h"
#include "entities/board.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

using CastleState = Rook::CastleState;

vec_uptr<Move> Rook::possible_moves_no_check(const Board& board) const {
    return check_across(board);
}

void Rook::print(std::ostream& os) const {
    common_print(os, 'r');
}

std::unique_ptr<Piece> Rook::clone() const {
    return std::make_unique<Rook>(*this);
}

CastleState Rook::check_black_castle() const {
    if (_location.rank() == 7 && _location.file() == 0) {
        return CastleState::CAN_CASTLE_QUEENSIDE;
    }
    if (_location.rank() == 7 && _location.file() == 7) {
        return CastleState::CAN_CASTLE_KINGSIDE;
    }
    return CastleState::CANNOT_CASTLE;
}

CastleState Rook::check_white_castle() const {
    if (_location.rank() == 0 && _location.file() == 0) {
        return CastleState::CAN_CASTLE_QUEENSIDE;
    }
    if (_location.rank() == 0 && _location.file() == 7) {
        return CastleState::CAN_CASTLE_KINGSIDE;
    }
    return CastleState::CANNOT_CASTLE;
}

CastleState Rook::castle_state() const {
    if (!_was_moved) {
        switch (_color) {
        case Color::WHITE:
            return check_white_castle();

        case Color::BLACK:
            return check_black_castle();

        default:
            break; // TODO: add some error here
        }
    }
    return CastleState::CANNOT_CASTLE;
}

void Rook::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
