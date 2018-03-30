#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "entities/pieces/base_piece.h"

class Knight : public BasePiece {
private:


public:
    Knight() = default;
    Knight(const BasePiece::PieceColor color);

    virtual ~Knight() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;
};

#endif