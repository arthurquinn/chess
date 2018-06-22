#ifndef __BISHOP_H
#define __BISHOP_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Bishop : public BasePiece {
private:

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Bishop() = delete;
    Bishop(const Color color, const Location& location) 
            : BasePiece(color, location) {  }

    virtual ~Bishop() = default;

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<Piece> clone() const override;
};

#endif
