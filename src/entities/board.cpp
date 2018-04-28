#include "entities/board.h"
#include "factories/piece_factory.h"
#include "entities/pieces/base_piece.h"

#include "environment/chess_environment.h"

#include <cstdlib>

using namespace ChessEnv;

Board::Board(const Board& copy) {
    operator=(copy);
}

Board& Board::operator=(const Board& copy) {
    if (this != &copy) {
        for (int i = 0; i < BOARD_DIM; i++) {
            for (int j = 0; j < BOARD_DIM; j++) {
                _board[i][j] = copy.empty(i, j) ? copy._board[i][j]->clone() : nullptr;
            }
        }
    }
    return *this;
}

Board::Board(Board&& move) {
    operator=(std::move(move));
}

Board& Board::operator=(Board&& move) {
    if (this != &move) {
        for (int i = 0; i < BOARD_DIM; i++) {
            for (int j = 0; j < BOARD_DIM; j++) {
                _board[i][j] = std::move(move._board[i][j]);
            }
        }
    }
    return *this;
}

void Board::create_minor_row(const PieceFactory& pf, const int row, const PieceColor color) {
    int i = 0;
    for (auto& data : _board[row]) {
        data = pf.createPawn(color, row, i++);
    }
}

void Board::create_major_row(const PieceFactory& pf, const int row, const PieceColor color) {
    _board[row][0] = pf.createRook(color, row, 0);
    _board[row][1] = pf.createKnight(color, row, 1);
    _board[row][2] = pf.createBishop(color, row, 2);
    _board[row][3] = pf.createQueen(color, row, 3);
    _board[row][4] = pf.createKing(color, row, 4);
    _board[row][5] = pf.createBishop(color, row, 5);
    _board[row][6] = pf.createKnight(color, row, 6);
    _board[row][7] = pf.createRook(color, row, 7);
}

bool Board::pre_check(const Location& from, const Location& to) const {
    (void)from;
    (void)to;

    return false;
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

void Board::clear() {
    for (auto& row : _board) {
        for (auto& data : row) {
            data = std::unique_ptr<BasePiece>();
        }
    }
}

void Board::setup() {
    PieceFactory pf;

    clear();
    create_minor_row(pf, 1, PieceColor::WHITE);
    create_minor_row(pf, 6, PieceColor::BLACK);
    create_major_row(pf, 0, PieceColor::WHITE);
    create_major_row(pf, 7, PieceColor::BLACK);
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
