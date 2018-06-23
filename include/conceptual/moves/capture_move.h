#ifndef __CAPTURE_MOVE_H
#define __CAPTURE_MOVE_H

#include "interfaces/move.h"
#include "interfaces/piece.h"
#include "conceptual/location.h"

#include <memory>

class CaptureMove : public Move {
public:
    using Color = Piece::Color;

private:
    Color _color;

    Location _src;
    Location _dest;

    std::unique_ptr<Piece> _captured;

public:
    CaptureMove() = delete;
    CaptureMove(const Color color, const Location& src, const Location& dest) :
            _color(color), _src(src), _dest(dest) {  }

    virtual ~CaptureMove() = default;

    virtual void perform(Board& board) const override;
};

#endif
