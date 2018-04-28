#ifndef __ACTION_H
#define __ACTION_H

#include <string>
#include <utility>

class Board;
class Player;

class Action {
private:

public:
    enum class ValidationResult {
        LEGAL,
        ILLEGAL_NULL_PIECE,
        ILLEGAL_PLAYER_OWNERSHIP,
        ILLEGAL_MOVE,
    };

    enum class ActionResult {
        FAILURE,
        SUCCESS_SAME_TURN,
        SUCCESS_TURN_COMPLETE,
    };

    Action() = default;
    virtual ~Action() = default;

    virtual ValidationResult validate(const Player& player, const Board& board) const = 0;
    virtual ActionResult run(Player& player, Board& board) const = 0;
};

#endif
