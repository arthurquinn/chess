#include "entities/pieces/rook.h"
#include "entities/board.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

#include <climits>

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

using CastlePosition = Rook::CastlePosition;
using Color = Piece::Color;

std::vector<Location> Rook::line_of_sight(const Board& board) const {
    return check_across(board);
}

void Rook::print(std::ostream& os) const {
    common_print(os, 'r');
}

std::unique_ptr<Piece> Rook::clone() const {
    return std::make_unique<Rook>(*this);
}

unsigned int Rook::starting_rank() const {
    switch (_color) {
    case Color::WHITE:
        return 0;
    
    case Color::BLACK:
        return 7;

    default:
        // TODO: some error
        return UINT_MAX;
    }
}

CastlePosition Rook::in_castle_position() const {
    if (is_kingside()) {
        return CastlePosition::IN_POSITION_KINGSIDE;
    }
    if (is_queenside()) {
        return CastlePosition::IN_POSITION_QUEENSIDE;
    }
    return CastlePosition::NOT_IN_POSITION;
}

void Rook::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
