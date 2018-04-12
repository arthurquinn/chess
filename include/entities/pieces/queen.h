#ifndef __QUEEN_H
#define __QUEEN_H

#include "entities/pieces/base_piece.h"

class Queen : public BasePiece {
private:


public:
    Queen() = delete;
    Queen(const BasePiece::PieceColor color);

    virtual ~Queen() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;
};



#endif
