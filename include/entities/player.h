#ifndef __PLAYER_H
#define __PLAYER_H

#include <map>
#include <vector>

#include "entities/pieces/base_piece.h"

class King;

class Player {
private:
    using PlayerColor = BasePiece::PieceColor;
    using Pieces = std::vector<std::shared_ptr<BasePiece>>;
    using CapitalPiece = std::shared_ptr<King>;

    PlayerColor _color { PlayerColor::INVALID };

    Pieces _active_pieces;
    Pieces _graveyard;

    CapitalPiece _king;

public:
    Player() = default;
    virtual ~Player() = default;

    Player initialize(const PlayerColor color, const Pieces& starting_pieces, const CapitalPiece& king) const;
};


#endif
