#include "controllers/keyboard.h"
#include "interfaces/action.h"

#include "actions/move_piece.h"
#include "actions/query_moves.h"

#include <iostream>
#include <sstream>

template<typename T>
using opt = std::experimental::optional<T>;

Keyboard::TokenList Keyboard::split(const std::string& str, const char delim) const {
    TokenList tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

opt<BasePiece::Location> Keyboard::parse_loc(const std::string& strloc) const {
    opt<BasePiece::Location> empty;
    if (strloc.size() == 2) {
        const auto r = rank2ordinal(strloc.at(1));
        const auto f = file2ordinal(strloc.at(0));
        if (r < 8 && f < 8) {
            return opt<BasePiece::Location>(BasePiece::Location(r, f));
        }
    }
    return empty;
}

std::unique_ptr<Action> Keyboard::parse_move(const TokenList& tokens) const {
    if (tokens.size() > 2) {
        const auto from = parse_loc(tokens[1]);
        const auto to = parse_loc(tokens[2]);
        if (from && to) return std::make_unique<MovePiece>(from.value(), to.value());
    }
    return nullptr;
}

std::unique_ptr<Action> Keyboard::parse_possible(const TokenList& tokens) const {
    if (tokens.size() > 1) {
        const auto loc = parse_loc(tokens[1]);
        if (loc) return std::make_unique<QueryMoves>(loc.value());
    }
    return nullptr;
}

std::unique_ptr<Action> Keyboard::get() {
    std::string in;
    std::unique_ptr<Action> action;
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
        if (action) return action;
    }
}