#include "entities/pieces/queen.h"
#include "entities/board.h"
#include "helpers/stl_helper.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

std::vector<Location> Queen::line_of_sight(const Board& board) const {
    std::vector<Location> locs;
    STL_Helper::append_vectors(locs, check_across(board));
    STL_Helper::append_vectors(locs, check_diagonals(board));
    return locs;
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
