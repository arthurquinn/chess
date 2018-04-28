#include "entities/player.h"
#include "entities/board.h"
#include "entities/pieces/king.h"
#include "environment/chess_environment.h"
#include "factories/piece_factory.h"

using namespace ChessEnv;

using Location = BasePiece::Location;

Player::Player(const PlayerColor color) : _color(color) {

}

void Player::place_and_add(const std::shared_ptr<BasePiece>& piece, Board& board, const int r, const int f) {
    board.place(piece, r, f);
    _active_pieces.push_back(piece);
}

void Player::create_minor_row(const PieceFactory& pf, Board& board) {
    const int rank = _color == PlayerColor::WHITE ? 1 : 6;
    for (int file = 0; file < Board::BOARD_DIM; file++) {
        place_and_add(pf.createPawn(_color, rank, file), board, rank, file);
    }
}

void Player::create_major_row(const PieceFactory& pf, Board& board) {
    const int rank = _color == PlayerColor::WHITE ? 0 : 7;
    place_and_add(pf.createRook(_color, rank, 0), board, rank, 0);
    place_and_add(pf.createKnight(_color, rank, 1), board, rank, 1);
    place_and_add(pf.createBishop(_color, rank, 2), board, rank, 2);
    place_and_add(pf.createQueen(_color, rank, 3), board, rank, 3);
    place_and_add(pf.createBishop(_color, rank, 5), board, rank, 5);
    place_and_add(pf.createKnight(_color, rank, 6), board, rank, 6);
    place_and_add(pf.createRook(_color, rank, 7), board, rank, 7);
    
    const auto& king = std::make_shared<King>(_color, rank, 4);
    board.place(king, rank, 4);
    _active_pieces.push_back(king);
    _king = king;
}

bool Player::owns_piece(const BasePiece& piece) const {
    return _color == piece.color();
}

const King& Player::king() const {
    return *_king;
}

void Player::setup(Board& board) {
    PieceFactory pf;
    create_minor_row(pf, board);
    create_major_row(pf, board);
}
