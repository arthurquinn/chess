#ifndef __PLAYER_H
#define __PLAYER_H

#include <vector>
#include "entities/pieces/base_piece.h"

class Board;
class King;
class PieceFactory;

class Player {
private:
    using PlayerColor = BasePiece::PieceColor;
    using Location = BasePiece::Location;

    const PlayerColor _color;

    std::shared_ptr<King> _king;

    std::vector<std::shared_ptr<BasePiece>> _active_pieces;
    std::vector<std::shared_ptr<BasePiece>> _graveyard;

    void place_and_add(const std::shared_ptr<BasePiece>& piece, Board& board, const int r, const int f);
    void create_minor_row(const PieceFactory& pf, Board& board);
    void create_major_row(const PieceFactory& pf, Board& board);

public:
    Player() = delete;
    Player(const PlayerColor color);

    virtual ~Player() = default;

    bool owns_piece(const BasePiece& piece) const;

    const King& king() const;

    void setup(Board& board);
};


#endif
