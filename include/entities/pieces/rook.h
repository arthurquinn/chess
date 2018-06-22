#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Rook : public BasePiece {
private:
    bool _was_moved { false };

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    Rook() = delete;
    Rook(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Rook() = default;

    inline virtual void move(const Location& dest) override {
        BasePiece::move(dest);
        _was_moved = true;
    }

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<BasePiece> clone() const override;
};

#endif
