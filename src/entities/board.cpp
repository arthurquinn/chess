#include "entities/board.h"

#include "environment/chess_environment.h"

#include <cstdlib>

using namespace ChessEnv;
using PieceColor = BasePiece::PieceColor;

Board::Board(const Board& copy) {
    operator=(copy);
}

Board& Board::operator=(const Board& copy) {
    if (this != &copy) {
        for (int r = 0; r < BOARD_DIM; r++) {
            for (int f = 0; f < BOARD_DIM; f++) {
                if (copy._board[r][f]) {
                    _board[r][f] = copy._board[r][f]->clone();
                }
            }
        }
    }
    return *this;
}

Board::Board(Board&& move) {
    (void)move;
}

Board& Board::operator=(Board&& move) {
    (void)move;
    return *this;
}

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

Board Board::setup(std::vector<BoardData> pieces) const {
    Board nboard;
    for (const auto& piece : pieces) {
        const auto& loc = piece->get_location();
        nboard._board[loc.first][loc.second] = piece;
    }
    return nboard;
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
