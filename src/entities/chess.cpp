#include "entities/chess.h"

#include <iostream>

using Color = BasePiece::Color;
using Location = BasePiece::Location;

void Chess::initialize() {
    _turn_color = Color::WHITE;
    _board.setup();
}

void Chess::move_piece(const Location& src, const Location& dest) {
    // if (_board.empty(src)) {
    //     std::cout << "no piece at location: [" << src.first << ", " << src.second << "]" << std::endl;
    //     return;
    // }
    // if (_board.at(src).is_adversary(_turn_color)) {
    //     std::cout << "piece at location: [" << src.first << ", " << src.second << "] belongs to adversary" << std::endl;
    //     return;
    // }
    // if (_board.legal)
}

void Chess::possible_moves(const Location& query) {
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
        std::cout << "Location: [" << query.first << ", " << query.second << "]" << std::endl;
    }
}

