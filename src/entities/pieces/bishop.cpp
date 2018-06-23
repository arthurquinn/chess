#include "entities/pieces/bishop.h"
#include "entities/board.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

vec_uptr<Move> Bishop::possible_moves_no_check(const Board& board) const {
    return check_diagonals(board);
}

void Bishop::print(std::ostream& os) const {
    common_print(os, 'b');
}

std::unique_ptr<Piece> Bishop::clone() const {
    return std::make_unique<Bishop>(*this);
}

void Bishop::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
