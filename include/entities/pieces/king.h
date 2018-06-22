#ifndef __KING_H
#define __KING_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class King : public BasePiece {
private:
    bool _was_moved { false };

public:
    using Location = BasePiece::Location;
    using Color = BasePiece::Color;

    King() = delete;
    King(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~King() = default;

    inline virtual void move(const Location& dest) override {
        BasePiece::move(dest);
        _was_moved = true;
    }

    bool in_check(const Board& board) const;

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<BasePiece> clone() const override;

    virtual inline bool is_king() const { return true; }
};

#endif
