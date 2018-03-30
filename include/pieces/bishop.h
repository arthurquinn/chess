#ifndef __BISHOP_H
#define __BISHOP_H

#include "pieces/base_piece.h"

class Bishop : public BasePiece {
private:


public:
    Bishop() = default;
    Bishop(const BasePiece::PieceColor color);

    virtual ~Bishop() = default;
};


#endif
