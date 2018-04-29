#include "entities/game.h"
#include "environment/chess_environment.h"
#include "interfaces/action.h"
#include "entities/pieces/pawn.h"
#include "entities/pieces/rook.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/king.h"
#include "entities/pieces/queen.h"
#include "entities/player.h"

using namespace ChessEnv;

void Game::shift_turn() {
    switch (_turn_color) {
    case PlayerColor::BLACK:
        _turn_color = PlayerColor::WHITE;
        break;
    case PlayerColor::WHITE:
        _turn_color = PlayerColor::BLACK;
        break;
    default:
        env.utilities.logger.error("invalid turn color");
        break;
    }
}

Game::GamePieces Game::create_minor_row(const PlayerColor color) const {
    GamePieces pieces;
    const int r = color == PlayerColor::WHITE ? 1 : 6;
    for (int f = 0; f < Board::BOARD_DIM; f++) {
        pieces.push_back(std::make_shared<Pawn>(color, r, f));
    }
    return pieces;
}

Game::GamePieces Game::create_major_row(const PlayerColor color) const {
    GamePieces pieces;
    const int r = color == PlayerColor::WHITE ? 0 : 7;
    pieces.push_back(std::make_shared<Rook>(color, r, 0));
    pieces.push_back(std::make_shared<Knight>(color, r, 1));
    pieces.push_back(std::make_shared<Bishop>(color, r, 2));
    pieces.push_back(std::make_shared<Queen>(color, r, 3));
    pieces.push_back(std::make_shared<Bishop>(color, r, 5));
    pieces.push_back(std::make_shared<Knight>(color, r, 6));
    pieces.push_back(std::make_shared<Rook>(color, r, 7));
    return pieces;
}

Game::GamePieces Game::create_pieces_for_color(const PlayerColor color) const {
    GamePieces pieces;

    const auto& minor_pieces = create_minor_row(color);
    const auto& major_pieces = create_major_row(color);

    pieces.insert(std::end(pieces), std::begin(minor_pieces), std::end(minor_pieces));
    pieces.insert(std::end(pieces), std::begin(major_pieces), std::end(major_pieces));
    return pieces;
}

Game::PlayerKing Game::create_king_for_color(const PlayerColor color) const {
    const int r = color == PlayerColor::WHITE ? 0 : 7;
    return std::make_shared<King>(color, r, 4);
}

bool Game::active() const {
    return _state == GameState::READY || _state == GameState::RUNNING;
}

std::unique_ptr<Game> Game::setup() const {
    auto ugame = std::make_unique<Game>();

    const auto& white_pieces = ugame->create_pieces_for_color(PlayerColor::WHITE);
    const auto& black_pieces = ugame->create_pieces_for_color(PlayerColor::BLACK);

    const auto& white_king = ugame->create_king_for_color(PlayerColor::WHITE);
    const auto& black_king = ugame->create_king_for_color(PlayerColor::BLACK);

    GamePieces all_pieces;
    all_pieces.insert(std::end(all_pieces), std::begin(white_pieces), std::end(white_pieces));
    all_pieces.insert(std::end(all_pieces), std::begin(black_pieces), std::end(black_pieces));
    all_pieces.push_back(white_king);
    all_pieces.push_back(black_king);

    ugame->_state = GameState::READY;
    ugame->_turn_color = PlayerColor::WHITE;
    ugame->_pieces = all_pieces;
    ugame->_kings = {
        { PlayerColor::WHITE, white_king },
        { PlayerColor::BLACK, black_king }
    };

    ugame->_board = ugame->_board.setup(all_pieces);
    ugame->_players = {
        { PlayerColor::WHITE, Player().initialize(PlayerColor::WHITE, white_pieces, white_king) },
        { PlayerColor::BLACK, Player().initialize(PlayerColor::BLACK, black_pieces, black_king) }
    };

    return ugame;
}

std::unique_ptr<Game> Game::reset() const {
    return nullptr;
}

std::unique_ptr<Game> Game::act(const Action& action) const {
    env.utilities.logger.debug("game received action");

    (void)action;
    return nullptr;
}

void Game::print(std::ostream& os) const {
    _board.print(os);
}
