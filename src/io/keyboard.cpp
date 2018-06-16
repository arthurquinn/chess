#include "io/keyboard.h"
#include "io/commands/move_piece.h"
#include "io/commands/possible_moves.h"

#include <sstream>
#include <iostream>

using namespace std::experimental;

Keyboard::TokenList Keyboard::split(const std::string& str, const char delim) const {
    TokenList tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

Keyboard::opt<Keyboard::Location> Keyboard::parse_loc(const std::string& str) const {
    if (str.size() == 2) {
        const auto r = rank2ordinal(str.at(1));
        const auto f = file2ordinal(str.at(0));
        if (r < 8 && f < 8) {
            return Location(r, f);
        }
    }
    return nullopt;
}

std::unique_ptr<Command> Keyboard::parse_move_piece(const TokenList& tokens) const {
    if (tokens.size() > 2) {
        const auto& from = parse_loc(tokens[1]);
        const auto& to = parse_loc(tokens[2]);
        if (from && to) return std::make_unique<MovePiece>(from.value(), to.value());
    }
    return nullptr;
}
std::unique_ptr<Command> Keyboard::parse_possible_moves(const TokenList& tokens) const {
    if (tokens.size() > 1) {
        const auto& loc = parse_loc(tokens[1]);
        if (loc) return std::make_unique<PossibleMoves>(loc.value());
    }
    return nullptr;
}

std::unique_ptr<Command> Keyboard::getCommand() const {
    std::string in;
    std::unique_ptr<Command> command;
    // TODO: implement some interruption mechanism
    for (;;) {
        if (std::getline(std::cin, in).good()) {
            const auto tokens = split(in, ' ');
            if (tokens[0] == "move") {
                command = parse_move_piece(tokens);
            } else if (tokens[0] == "possible") {
                command = parse_possible_moves(tokens);
            }
        }
        if (command) return command;
    }
}
