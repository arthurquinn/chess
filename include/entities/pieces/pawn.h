#ifndef __PAWN_H
#define __PAWN_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Pawn : public BasePiece {
private:

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Pawn() = delete;
    Pawn(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Pawn() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
