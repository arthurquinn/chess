#include "entities/player.h"
#include "entities/board.h"
#include "environment/chess_environment.h"

using namespace ChessEnv;

Player::Player(const PlayerColor color) : _color(color) {

}

bool Player::owns_piece(const BasePiece& piece) const {
    return _color == piece.color();
}

void Player::assign_pieces(const Board& board) {
    int r = _color == PlayerColor::WHITE ? 0 : Board::BOARD_DIM - 1;
    const int dr = _color == PlayerColor::WHITE ? 1 : -1;

    for (int i = 0; i < 2; i++) {
        for (int f = 0; f < Board::BOARD_DIM; f++) {
            _active_pieces.push_back(board.at(r, f));
        }
        r += dr;
    }

    switch (_color) {
        case PlayerColor::WHITE:
            _king = board.at(0, 4);
            break;
        case PlayerColor::BLACK:
            _king = board.at(7, 4);
            break;
        default:
            env.utilities.logger.error("bad player color");
            break;
    } 
}

const std::shared_ptr<BasePiece>& Player::king() const {
    return _king;
}

