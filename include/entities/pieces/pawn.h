#ifndef __PAWN_H
#define __PAWN_H

#include "entities/pieces/base_piece.h"

class Pawn : public BasePiece {
private:


public:
    Pawn() = delete;
    Pawn(const BasePiece::PieceColor color);

    virtual ~Pawn() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;
};


#endif
