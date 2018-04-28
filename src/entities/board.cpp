#include "entities/board.h"
#include "factories/piece_factory.h"
#include "entities/pieces/base_piece.h"
#include "entities/player.h"

#include "environment/chess_environment.h"

#include <cstdlib>

using namespace ChessEnv;

bool Board::in_bounds(const int r, const int f) const {
    return r - Board::BOARD_DIM < 0 && f - Board::BOARD_DIM < 0;
}

bool Board::in_bounds(const Location& location) const {
    return in_bounds(location.first, location.second);
}

bool Board::empty(const int r, const int f) const {
    return at(r, f) == nullptr;
}

bool Board::empty(const Location& location) const {
    return empty(location.first, location.second);
}

const Board::BoardData& Board::at(const int r, const int f) const {
    return _board[r][f];
}

const Board::BoardData& Board::at(const Location& location) const {
    return at(location.first, location.second);
}

void Board::place(const BoardData& bd, const Location& location) {
    place(bd, location.first, location.second);
}

void Board::place(const BoardData& bd, const int r, const int f) {
    _board[r][f] = bd;
}

void Board::move(const int sr, const int sf, const int tr, const int tf) {
    _board[tr][tf] = std::move(_board[sr][sf]);
    if (_board[tr][tf] == nullptr) {
        env.utilities.logger.fatal("attempted to move from location with no piece");
        std::abort();
    }
    _board[tr][tf]->move(tr, tf);
}

void Board::move(const Location& sloc, const Location& tloc) {
    move(sloc.first, sloc.second, tloc.first, tloc.second);
}

void Board::clear() {
    for (auto& row : _board) {
        for (auto& data : row) {
            data = nullptr;
        }
    }
}

void Board::print(std::ostream& os) const {
    char rank = '8';
    auto row = _board.crbegin();
    for (; row != _board.crend(); row++) {
        os << rank-- << " ";
        for (const auto& data : *row) {
            if (data) {
                data->print(os);
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
    os << std::endl;
}
