#ifndef __KNIGHT_H
#define __KNIGHT_H

#include "entities/pieces/base_piece.h"

class Knight : public BasePiece {
private:
    const std::vector<std::pair<const int, const int>> L_MOVES;

public:
    Knight() = delete;
    Knight(const BasePiece::PieceColor color);

    virtual ~Knight() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;
};

#endif
