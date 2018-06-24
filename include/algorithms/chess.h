#ifndef __CHESS_H
#define __CHESS_H

#include "interfaces/piece.h"

#include <memory>
#include <vector>

class Move;
class Board;

class King;
class Rook;

class Chess {
private:
    static bool can_kingside_castle(const Board& board, const King& king, const Rook& rook);
    static bool can_queenside_castle(const Board& board, const King& king, const Rook& rook);

public:
    template<typename T>
    using vec_uptr = std::vector<std::unique_ptr<T>>;

    using Color = Piece::Color;

    Chess() = delete;
    ~Chess() = delete;

    static vec_uptr<Move> check_castle(const Board& board, const Color color);

    static bool king_in_check(const Board& board, const Color color);

    static bool king_in_checkmate(const Board& board, const Color color);
};

#endif
