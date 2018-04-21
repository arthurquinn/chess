#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "entities/pieces/base_piece.h"

class Knight : public BasePiece {
private:
    const std::vector<BasePiece::Location> L_MOVES;

public:
    Knight() = delete;
    Knight(const BasePiece::PieceColor color, const int r, const int f);

    virtual ~Knight() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;
};

#endif
