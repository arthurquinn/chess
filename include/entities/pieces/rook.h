#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

class Rook : public BasePiece {
private:

public:
    Rook() = default;
    Rook(const BasePiece::PieceColor color);

    virtual ~Rook() = default;
};


#endif
