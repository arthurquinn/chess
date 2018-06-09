#ifndef __PAWN_H
#define __PAWN_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Pawn : public BasePiece {
private:

public:
    using Location = BasePiece::Location;

    Pawn() = default;
    virtual ~Pawn() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
