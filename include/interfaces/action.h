#ifndef __ACTION_H
#define __ACTION_H

#include <string>
#include <utility>

class Board;
class Game;

class Action {
private:

public:
    enum class ValidationResult {
        LEGAL,
        ILLEGAL
    };

    enum class ActionResult {
        SUCCESS
    };

    using ValidationResponse = std::pair<ValidationResult, std::string>;
    using ActionResponse = std::pair<ActionResult, std::string>;

    Action() = default;
    virtual ~Action() = default;

    virtual ValidationResponse validate(const Game& game) const = 0;
    virtual ActionResponse run(const Board& board) const = 0;
};

#endif
