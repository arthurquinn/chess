#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

class Rook : public BasePiece {
private:

public:
    Rook() = delete;
    Rook(const BasePiece::PieceColor color, const int r, const int f);

    virtual ~Rook() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::shared_ptr<BasePiece> clone() const override;
};


#endif
