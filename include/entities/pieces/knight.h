#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Knight : public BasePiece {
private:

public:
    using Location = BasePiece::Location;

    Knight() = default;
    virtual ~Knight() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
