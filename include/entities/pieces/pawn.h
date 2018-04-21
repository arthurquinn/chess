#ifndef __PAWN_H
#define __PAWN_H

#include "entities/pieces/base_piece.h"

class Pawn : public BasePiece {
private:
    bool _was_moved { false };

public:
    Pawn() = delete;
    Pawn(const BasePiece::PieceColor color, const int r, const int f);

    virtual ~Pawn() = default;

    virtual void move(const int r, const int f) override;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;
};


#endif
