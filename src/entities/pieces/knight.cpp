#include "entities/pieces/knight.h"
#include "entities/board.h"
#include "conceptual/moves/basic_move.h"
#include "interfaces/visitors/piece_visitor.h"

template<typename T>
using vec_uptr = Piece::vec_uptr<T>;

const std::array<std::pair<int, int>, 8> Knight::L_MOVES = {
    std::make_pair( 1,  2),
    std::make_pair( 1, -2),
    std::make_pair(-1,  2),
    std::make_pair(-1, -2),
    std::make_pair( 2,  1),
    std::make_pair( 2, -1),
    std::make_pair(-2,  1),
    std::make_pair(-2, -1)
};

vec_uptr<Move> Knight::possible_moves_no_check(const Board& board) const {
    vec_uptr<Move> moves;
    for (const auto& l : L_MOVES) {
        const auto& rank = _location.rank() + l.first;
        const auto& file = _location.file() + l.second;
        if (can_move(board, rank, file)) {
            moves.push_back(std::make_unique<BasicMove>(_color, _location, Location(rank, file)));
        }
    }
    return moves;
}

void Knight::print(std::ostream& os) const {
    common_print(os, 'n');
}

std::unique_ptr<Piece> Knight::clone() const {
    return std::make_unique<Knight>(*this);
}

void Knight::accept(PieceVisitor& visitor) const {
    visitor.visit(*this);
}
