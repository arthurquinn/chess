#ifndef __BISHOP_H
#define __BISHOP_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Bishop : public BasePiece {
private:

public:
    using Location = BasePiece::Location;

    Bishop() = default;
    virtual ~Bishop() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
