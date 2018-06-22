#ifndef __QUEEN_H
#define __QUEEN_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Queen : public BasePiece {
private:

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Queen() = delete;
    Queen(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Queen() = default;

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<Piece> clone() const override;
};

#endif
