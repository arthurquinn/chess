#ifndef __PAWN_H
#define __PAWN_H

#include "pieces/base_piece.h"

class Pawn : public BasePiece {
private:


public:
    Pawn() = default;
    Pawn(const BasePiece::PieceColor color);

    virtual ~Pawn() = default;
};


#endif
