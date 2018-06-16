#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Rook : public BasePiece {
private:

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Rook() = delete;
    Rook(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Rook() = default;

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;
    virtual std::vector<Location> possible_moves(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<BasePiece> clone() const override;
};

#endif
