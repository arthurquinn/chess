#ifndef __MOVE_PIECE_H
#define __MOVE_PIECE_H

#include "interfaces/command.h"
#include "conceptual/location.h"

class MovePiece : public Command {
private:
    Location _src;
    Location _dest;

public:
    MovePiece() = delete;
    MovePiece(const Location& src, const Location& dest) :
            _src(src),
            _dest(dest) { }

    virtual ~MovePiece() = default;

    virtual void run(Chess& chess) const override;
};

#endif
