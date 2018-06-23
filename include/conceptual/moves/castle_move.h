#ifndef __CASTLE_MOVE_H
#define __CASTLE_MOVE_H

#include "interfaces/move.h"
#include "interfaces/piece.h"

class CastleMove : public Move {
public:
    using Color = Piece::Color;

    enum class Type {
        QUEENSIDE,
        KINGSIDE
    };

private:
    Color _color;
    Type _type;

public:
    CastleMove() = delete;
    CastleMove(const Color color, const Type type) :
            _color(color), _type(type) {  }

    virtual ~CastleMove() = default;

    virtual void perform(Board& board) const override;
};

#endif
