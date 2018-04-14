#ifndef __PLAYER_H
#define __PLAYER_H

#include "entities/pieces/base_piece.h"

class Player {
private:
    using PlayerColor = BasePiece::PieceColor;

    const PlayerColor _color = PlayerColor::INVALID;

public:
    Player() = delete;
    Player(const PlayerColor color);

    virtual ~Player() = default;
};


#endif
