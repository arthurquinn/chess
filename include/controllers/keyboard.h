#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "interfaces/controller.h"

#include <experimental/optional>
#include <vector>
#include <string>

class Keyboard : public Controller {
private:
    using OptAction = std::experimental::optional<Action>;
    using TokenList = std::vector<std::string>;

    TokenList split(const std::string& str, const char delim) const;

    OptAction handle_move(const TokenList& tokens) const;

    OptAction handle_possible(const TokenList& tokens) const;

public:
    Keyboard() = default;
    virtual ~Keyboard() = default;

    Action get() override;
};


#endif
