#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "pieces/base_piece.h"

class Knight : public BasePiece {
private:


public:
    Knight() = default;
    Knight(const BasePiece::PieceColor color);

    virtual ~Knight() = default;
};

#endif
