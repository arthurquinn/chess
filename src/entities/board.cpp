#include "entities/board.h"
#include "factories/piece_factory.h"
#include "entities/pieces/base_piece.h"

void Board::create_minor_row(const PieceFactory& pf, const unsigned char row, const PieceColor color) {
    for (auto& data : _board[row]) {
        data = pf.createPawn(color);
    }
}

void Board::create_major_row(const PieceFactory& pf, const unsigned char row, const PieceColor color) {
    _board[row][0] = pf.createRook(color);
    _board[row][1] = pf.createKnight(color);
    _board[row][2] = pf.createBishop(color);
    _board[row][3] = pf.createQueen(color);
    _board[row][4] = pf.createKing(color);
    _board[row][5] = pf.createBishop(color);
    _board[row][6] = pf.createKnight(color);
    _board[row][7] = pf.createRook(color);
}

const Board::BoardData& Board::at(const int x, const int y) const {
    return _board[x][y];
}

const Board::BoardData& Board::at(const Location location) const {
    return at(location.first, location.second);
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
    for (const auto& row : _board) {
        os << rank-- << " ";
        for (const auto& data : row) {
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
