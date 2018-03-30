#ifndef __KING_H
#define __KING_H

#include "entities/pieces/base_piece.h"

class King : public BasePiece {
private:


public:
    King() = default;
    King(const BasePiece::PieceColor color);

    virtual ~King() = default;
};


#endif
