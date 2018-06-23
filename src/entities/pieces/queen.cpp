#include "entities/pieces/queen.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

vec_uptr<Move> Queen::possible_moves_no_check(const Board& board) const {
    vec_uptr<Move> moves;
    STL_Helper::merge_vectors(moves, check_across(board));
    STL_Helper::merge_vectors(moves, check_diagonals(board));
    return moves;
}

void Queen::print(std::ostream& os) const {
    common_print(os, 'q');
}

std::unique_ptr<Piece> Queen::clone() const {
    return std::make_unique<Queen>(*this);
}

void Queen::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
