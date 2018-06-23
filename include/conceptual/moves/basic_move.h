#ifndef __BASIC_MOVE_H
#define __BASIC_MOVE_H

#include "conceptual/location.h"
#include "interfaces/move.h"
#include "interfaces/piece.h"

class BasicMove : public Move {
public:
    using Color = Piece::Color;

private:
    Color _color;

    Location _src;
    Location _dest;

public:
    BasicMove() = delete;
    BasicMove(const Color color, const Location& src, const Location& dest) :
            _color(color), _src(src), _dest(dest) {  }

    virtual ~BasicMove() = default;

    virtual void perform(Board& board) const override;
};

#endif
