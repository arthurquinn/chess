#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "entities/pieces/base_piece.h"

#include <vector>
#include <map>
#include <utility>

class Board;

class Knight : public BasePiece {
private:
    static const std::array<std::pair<int, int>, 8> L_MOVES;

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Knight() = delete;
    Knight(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Knight() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;
};

#endif
