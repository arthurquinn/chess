#include "entities/pieces/bishop.h"
#include "entities/board.h"

using Location = Bishop::Location;

std::vector<Location> Bishop::possible_moves_no_check(const Board& board) const {
    return check_diagonals(board);
}

std::vector<Location> Bishop::possible_moves(const Board& board) const {
    const auto& no_check = possible_moves_no_check(board);

    auto simulation = board;

}

void Bishop::print(std::ostream& os) const {
    common_print(os, 'b');
}

std::unique_ptr<BasePiece> Bishop::clone() const {
    return std::make_unique<Bishop>(*this);
}
