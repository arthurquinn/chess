#ifndef __CHESS_H
#define __CHESS_H

#include "entities/board.h"
#include "entities/pieces/base_piece.h"

class Chess {
private:
    using Color = BasePiece::Color;

    Color _turn_color;
    Board _board;

public:
    Chess() = default;
    virtual ~Chess() = default;

    void initialize();

};

#endif
