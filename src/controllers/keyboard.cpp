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

Keyboard::OptLocation Keyboard::parse_loc(const std::string& strloc) const {
    OptLocation empty;
    if (strloc.size() == 2) {
        const auto x = file2ordinal(strloc.at(0));
        const auto y = rank2ordinal(strloc.at(1));
        if (x < 8 && y < 8) {
            return OptLocation(BasePiece::Location(x, y));
        }
    }
    return empty;
}

Keyboard::OptAction Keyboard::parse_move(const TokenList& tokens) const {
    OptAction empty;
    if (tokens.size() > 2) {
        const auto from = parse_loc(tokens[1]);
        const auto to = parse_loc(tokens[2]);
        if (from && to) return OptAction(MovePiece(from.value(), to.value()));
    }
    return empty;
}

Keyboard::OptAction Keyboard::parse_possible(const TokenList& tokens) const {
    OptAction empty;
    if (tokens.size() > 1) {
        const auto loc = parse_loc(tokens[1]);
        if (loc) return OptAction(QueryMoves(loc.value()));
    }
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
                action = parse_move(tokens);
            } else if (tokens[0] == "possible") {
                action = parse_possible(tokens);
            }
        }
        if (action) return action.value();
    }
}