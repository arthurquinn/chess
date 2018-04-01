#ifndef __BISHOP_H
#define __BISHOP_H

#include "entities/pieces/base_piece.h"

class Bishop : public BasePiece {
private:
    
public:
    Bishop() = delete;
    Bishop(const BasePiece::PieceColor color);

    virtual ~Bishop() = default;

    virtual const std::vector<Location> possible_moves(const Board& board) const override;
};


#endif
