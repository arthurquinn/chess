#ifndef __PLAYER_H
#define __PLAYER_H

#include "entities/pieces/base_piece.h"

class Player {
private:
    using PlayerColor = BasePiece::PieceColor;

    const PlayerColor _color;

public:
    Player() = delete;
    Player(const PlayerColor color);

    virtual ~Player() = default;

    inline bool owns_piece(const BasePiece& piece) const { return _color == piece.color(); }
};


#endif
