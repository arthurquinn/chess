#include "entities/chess.h"

#include <iostream>
#include <algorithm>

using Color = Piece::Color;

Color Chess::adversarial_color(const Color color) {
    switch (color) {
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
        std::cout << "no piece at location: [" << src.rank() << ", " << src.file() << "]" << std::endl;
        return;
    }
    if (_board.at(src).is_adversary(_turn_color)) {
        std::cout << "piece at location: [" << src.rank() << ", " << src.file() << "] belongs to adversary" << std::endl;
        return;
    }
    
    // TODO: fixme
    // const auto& possible = _board.at(src).possible_moves(_board);
    // if (std::find(possible.cbegin(), possible.cend(), dest) == possible.cend()) {
    //     std::cout << "move from location: [" << src.rank() << ", " << src.file() << "] to location: [" << dest.rank() << ", " << dest.file() << "] is not legal" << std::endl;
    //     return;
    // }

    // _board.move(src, dest);
    // _turn_color = adversarial_color(_turn_color);
}

void Chess::possible_moves(const Location& query) const {
    if (_board.empty(query)) {
        std::cout << "no piece at location: [" << query.rank() << ", " << query.file() << "]" << std::endl;
        return;
    }
    if (_board.at(query).is_adversary(_turn_color)) {
        std::cout << "piece at location: [" << query.rank() << ", " << query.file() << "] belongs to adversary" << std::endl;
        return;
    }

    // TODO: fixme
    // const auto& possible = _board.at(query).possible_moves(_board);
    // std::cout << "Possible moves:" << std::endl;
    // for (const auto& location : possible) {
    //     std::cout << "Location: [" << location.rank() << ", " << location.file() << "]" << std::endl;
    // }
}

void Chess::print(std::ostream& os) const {
    _board.print(os);
}

