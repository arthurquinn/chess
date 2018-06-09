#ifndef __QUEEN_H
#define __QUEEN_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Queen : public BasePiece {
private:

public:
    using Location = BasePiece::Location;

    Queen() = default;
    virtual ~Queen() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
