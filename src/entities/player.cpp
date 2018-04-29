#include "entities/player.h"

Player Player::initialize(const PlayerColor color, const Pieces& starting_pieces, const CapitalPiece& king) const {
    Player cplayer;
    cplayer._color = color;
    cplayer._active_pieces = starting_pieces;
    cplayer._king = king;
    return cplayer;
}