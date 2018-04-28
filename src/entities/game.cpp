#include "entities/game.h"
#include "environment/chess_environment.h"
#include "interfaces/action.h"

using namespace ChessEnv;

Game::PlayerColor Game::cycle(const PlayerColor color) {
    switch (color) {
    case PlayerColor::BLACK:
        _turn_color = PlayerColor::WHITE;
        break;
    case PlayerColor::WHITE:
        _turn_color = PlayerColor::BLACK;
        break;
    default:
        // TODO: log some error
        break;
    }
    return color;
}

void Game::setup() {
    _board.setup();
    _players.emplace(PlayerColor::WHITE, PlayerColor::WHITE);
    _players.emplace(PlayerColor::BLACK, PlayerColor::BLACK);
    _turn_color = PlayerColor::WHITE;
    _state = GameState::READY;
}

// void Game::run() {
//     if (_state == GameState::READY) {
//         _state = GameState::RUNNING;
//         while (_state == GameState::RUNNING) {
//             _players.at(cycle(_turn_color)).turn();
//         }
//     }
// }

void Game::reset() {
    _board.clear();
    _players.clear();
    _turn_color = PlayerColor::INVALID;
    _state = GameState::EMPTY;
}

void Game::act(const Action& action) {
    env.utilities.logger.debug("validating action");

    const auto& res = action.validate(_players.at(_turn_color), _board);
    switch (res) {
        case Action::ValidationResult::ILLEGAL_MOVE:
            env.utilities.logger.debug("illegal move");
            break;
        case Action::ValidationResult::ILLEGAL_NULL_PIECE:
            env.utilities.logger.debug("no piece at location");
            break;
        case Action::ValidationResult::ILLEGAL_PLAYER_OWNERSHIP:
            env.utilities.logger.debug("player does not own this piece");
            break;
        case Action::ValidationResult::LEGAL:
            action.run(_players.at(_turn_color), _board);
            break;
        default:
            env.utilities.logger.debug("invalid validation result");
            break;
    }
}

void Game::print(std::ostream& os) const {
    _board.print(os);
}

