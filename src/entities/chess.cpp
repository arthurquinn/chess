#include "entities/chess.h"

#include <iostream>
#include <algorithm>

using Color = BasePiece::Color;
using Location = BasePiece::Location;

Color Chess::adversial_color(const Color color) const {
    switch (_turn_color) {
    case Color::WHITE:
        return Color::BLACK;
    case Color::BLACK:
        return Color::WHITE;
    default:
        return Color::INVALID;
    }
}

void Chess::initialize() {
    _turn_color = Color::WHITE;
    _board.setup();
}

void Chess::move_piece(const Location& src, const Location& dest) {
    if (_board.empty(src)) {
        std::cout << "no piece at location: [" << src.first << ", " << src.second << "]" << std::endl;
        return;
    }
    if (_board.at(src).is_adversary(_turn_color)) {
        std::cout << "piece at location: [" << src.first << ", " << src.second << "] belongs to adversary" << std::endl;
        return;
    }
    
    const auto& possible = _board.at(src).possible_moves(_board);
    if (std::find(possible.cbegin(), possible.cend(), dest) == possible.cend()) {
        std::cout << "move from location: [" << src.first << ", " << src.second << "] to location: [" << dest.first << ", " << dest.second << "] is not legal" << std::endl;
        return;
    }

    _board.move(src, dest);
    _turn_color = adversial_color(_turn_color);
}

void Chess::possible_moves(const Location& query) const {
    if (_board.empty(query)) {
        std::cout << "no piece at location: [" << query.first << ", " << query.second << "]" << std::endl;
        return;
    }
    if (_board.at(query).is_adversary(_turn_color)) {
        std::cout << "piece at location: [" << query.first << ", " << query.second << "] belongs to adversary" << std::endl;
        return;
    }

    const auto& possible = _board.at(query).possible_moves(_board);
    std::cout << "Possible moves:" << std::endl;
    for (const auto& location : possible) {
        std::cout << "Location: [" << location.first << ", " << location.second << "]" << std::endl;
    }
}

void Chess::print(std::ostream& os) const {
    _board.print(os);
}

