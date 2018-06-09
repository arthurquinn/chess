#ifndef __KING_H
#define __KING_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class King : public BasePiece {
private:

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    King() = delete;
    King(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~King() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
