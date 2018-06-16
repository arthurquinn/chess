#include "entities/board.h"
#include "entities/pieces/base_piece.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/king.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/pawn.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/rook.h"

using Color = Board::Color;
using Location = Board::Location;

Board::Board() = default;
Board::~Board() = default;

void Board::create_minor_row(const Color color, const int rank) {
    for (int file = 0; file < BOARD_DIM; file++) {
        _board[rank][file] = std::make_unique<Pawn>(color, Location(rank, file));
    }
}

void Board::create_major_row(const Color color, const int rank) {
    _board[rank][0] = std::make_unique<Rook>(color, Location(rank, 0));
    _board[rank][1] = std::make_unique<Knight>(color, Location(rank, 1));
    _board[rank][2] = std::make_unique<Bishop>(color, Location(rank, 2));
    _board[rank][3] = std::make_unique<Queen>(color, Location(rank, 3));
    _board[rank][4] = std::make_unique<King>(color, Location(rank, 4));
    _board[rank][5] = std::make_unique<Bishop>(color, Location(rank, 5));
    _board[rank][6] = std::make_unique<Knight>(color, Location(rank, 6));
    _board[rank][7] = std::make_unique<Rook>(color, Location(rank, 7));

}

void Board::setup() {
    create_minor_row(Color::WHITE, 1);
    create_minor_row(Color::BLACK, 6);
    create_major_row(Color::WHITE, 0);
    create_major_row(Color::BLACK, 7);
}

void Board::clear() {
    for (auto& row : _board) {
        for (auto& data : row) {
            data = nullptr;
        }
    }
}

void Board::move(const Location& src, const Location& dest) {
    if (in_bounds(src) && in_bounds(dest)) {
        _board[dest.first][dest.second] =
                std::move(_board[src.first][src.second]);
        _board[dest.first][dest.second]->move(dest);
    }
}

void Board::print(std::ostream& os) const {
    char rank = '8';
    auto row = _board.crbegin();
    for (; row != _board.crend(); row++) {
        os << rank-- << " ";
        for (const auto& data : *row) {
            if (data) {
                os << " ";
                data->print(os);
                os << " ";
            } else {
                os << " -- ";
            }
        }
        os << std::endl;
    }
    char file = 'a';
    os << "   ";
    for (; file < 'i'; file++) {
        os << file << "   ";
    }

}
