#include "entities/pieces/rook.h"
#include "entities/board.h"

using Location = Rook::Location;

std::vector<Location> Rook::possible_moves_no_check(const Board& board) const {
    return check_across(board);
}

void Rook::print(std::ostream& os) const {
    common_print(os, 'r');
}

std::unique_ptr<BasePiece> Rook::clone() const {
    return std::make_unique<Rook>(*this);
}
