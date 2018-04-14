#include "controllers/keyboard.h"
#include "interfaces/action.h"

#include "actions/move_piece.h"
#include "actions/query_moves.h"

#include <iostream>
#include <sstream>

Keyboard::TokenList Keyboard::split(const std::string& str, const char delim) const {
    TokenList tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

Keyboard::OptAction Keyboard::handle_move(const TokenList& tokens) const {
    OptAction empty;
    if (tokens.size() > 2) {
        return OptAction(MovePiece(MovePiece::Location(0, 0), MovePiece::Location(0, 0)));
    }
    return empty;
}

Keyboard::OptAction Keyboard::handle_possible(const TokenList& tokens) const {

    (void)tokens;

    OptAction empty;
    return empty;
}

Action Keyboard::get() {
    std::string in;
    OptAction action;
    // TODO: implement some interruption mechanism
    for (;;) {
        if (std::getline(std::cin, in).good()) {
            const auto tokens = split(in, ' ');
            if (tokens[0] == "move") {
                action = handle_move(tokens);
            } else if (tokens[0] == "possible") {
                action = handle_possible(tokens);
            }
        }
        if (action) return action.value();
    }
}