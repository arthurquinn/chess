#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Rook : public BasePiece {
private:

public:
    using Location = BasePiece::Location;

    Rook() = default;
    virtual ~Rook() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
