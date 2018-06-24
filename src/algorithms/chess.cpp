#include "algorithms/chess.h"
#include "visitors/castle_visitor.h"
#include "interfaces/piece.h"
#include "entities/board.h"
#include "entities/pieces/king.h"
#include "entities/pieces/rook.h"
#include "conceptual/moves/castle_move.h"

template<typename T>
using vec_uptr = Chess::vec_uptr<T>;

using Color = Piece::Color;

bool Chess::can_kingside_castle(const Board& board, const King& king, const Rook& rook) {
    std::vector<Location> check_locs;
    check_locs.emplace_back(rook.starting_rank(), 5);
    check_locs.emplace_back(rook.starting_rank(), 6);

    // TODO: if king in check return false

    for (const auto& loc : check_locs) {
        if (board.occupied(loc)) {
            return false;
        }
        // TODO: if in check(loc) return false
    }

    return true;
}

bool Chess::can_queenside_castle(const Board& board, const King& king, const Rook& rook) {
    std::vector<Location> check_locs;
    check_locs.emplace_back(rook.starting_rank(), 2);
    check_locs.emplace_back(rook.starting_rank(), 3);

    // TODO: if king in check return false

    for (const auto& loc : check_locs) {
        if (board.occupied(loc)) {
            return false;
        }
        // TODO: if in check(loc) return false
    }

    if (board.occupied(rook.starting_rank(), 1)) {
        return false;
    }
    return true;
}

vec_uptr<Move> Chess::check_castle(const Board& board, const Color color) {
    vec_uptr<Move> moves;

    CastleVisitor castler(color);
    board.visit_pieces(castler);

    if (castler.has_king()) {

        if (castler.has_kingside_rook() &&
                can_kingside_castle(board, castler.get_king(), castler.get_kingside_rook())) {

            moves.push_back(std::make_unique<CastleMove>(color, CastleMove::Type::KINGSIDE));
        }

        if (castler.has_queenside_rook() &&
                can_queenside_castle(board, castler.get_king(), castler.get_queenside_rook())) {

            moves.push_back(std::make_unique<CastleMove>(color, CastleMove::Type::QUEENSIDE));
        }
    }
    return moves;
}

bool Chess::king_in_check(const Board& board, const Color color) {

}

bool Chess::king_in_checkmate(const Board& board, const Color color) {

}

