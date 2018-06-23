#ifndef __MOVE_H
#define __MOVE_H

class Board;

class Move {
public:
    Move() = default;
    virtual ~Move() = default;

    virtual void perform(Board& board) const = 0;
};

#endif
