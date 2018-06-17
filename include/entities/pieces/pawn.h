#ifndef __PAWN_H
#define __PAWN_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Pawn : public BasePiece {
public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

private:
    inline int move_direction() const {
        return _color == Color::WHITE ? 1 : -1;
    }

    bool _was_moved { false };

public:
    Pawn() = delete;
    Pawn(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Pawn() = default;

    inline virtual void move(const Location& dest) override {
        BasePiece::move(dest);
        _was_moved = true;
    }

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<BasePiece> clone() const override;

    virtual inline bool is_king() const { return false; }
};

#endif
