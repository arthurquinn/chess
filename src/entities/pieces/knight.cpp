#include "entities/pieces/knight.h"
#include "entities/board.h"
#include "conceptual/moves/basic_move.h"
#include "conceptual/moves/capture_move.h"
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

std::vector<Location> Knight::line_of_sight(const Board& board) const {
    std::vector<Location> locs;
    for (const auto& l : L_MOVES) {
        const auto& rank = _location.rank() + l.first;
        const auto& file = _location.file() + l.second;
        if (can_move(board, rank, file)) {
            locs.emplace_back(rank, file);
        }
        else if (can_capture(board, rank, file)) {
            locs.emplace_back(rank, file);
        }
    }
    return locs;
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
