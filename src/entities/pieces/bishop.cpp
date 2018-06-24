#include "entities/pieces/bishop.h"
#include "entities/board.h"
#include "interfaces/move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

std::vector<Location> Bishop::line_of_sight(const Board& board) const {
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
