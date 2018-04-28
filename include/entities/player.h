#ifndef __PLAYER_H
#define __PLAYER_H

#include <vector>
#include "entities/pieces/base_piece.h"

class Board;
class King;

class Player {
private:
    using PlayerColor = BasePiece::PieceColor;

    const PlayerColor _color;

    std::shared_ptr<BasePiece> _king;

    std::vector<std::shared_ptr<BasePiece>> _active_pieces;
    std::vector<std::shared_ptr<BasePiece>> _graveyard;

public:
    Player() = delete;
    Player(const PlayerColor color);

    virtual ~Player() = default;

    bool owns_piece(const BasePiece& piece) const;

    void assign_pieces(const Board& board);

    const std::shared_ptr<BasePiece>& king() const;
};


#endif
