#ifndef __MOVE_PIECE_H
#define __MOVE_PIECE_H

#include "interfaces/piece.h"
#include "interfaces/command.h"

class MovePiece : public Command {
public:
    using Location = Piece::Location;

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
