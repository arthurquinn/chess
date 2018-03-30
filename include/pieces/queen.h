#ifndef __QUEEN_H
#define __QUEEN_H

#include "pieces/base_piece.h"

class Queen : public BasePiece {
private:


public:
    Queen() = default;
    Queen(const BasePiece::PieceColor color);

    virtual ~Queen() = default;
};



#endif
