#ifndef __KING_H
#define __KING_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class King : public BasePiece {
public:
    enum class CastlePosition {
        NOT_IN_POSITION,
        IN_POSITION
    };

private:
    bool _was_moved { false };

public:
    using Color = BasePiece::Color;

    King() = delete;
    King(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~King() = default;

    inline virtual void move(const Location& dest) override {
        BasePiece::move(dest);
        _was_moved = true;
    }

    virtual std::vector<Location> line_of_sight(const Board& board) const override;

    virtual void print(std::ostream& os) const override;

    virtual std::unique_ptr<Piece> clone() const override;

    virtual void accept(PieceVisitor& visitor) const override;

    CastlePosition in_castle_position() const;

    bool in_check(const Board& board) const;
};

#endif
