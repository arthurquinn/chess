#include "entities/game.h"
#include "environment/chess_environment.h"

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
    env.utilities.logger.debug("running action");

    const auto vresult = action.validate(_players.at(_turn_color), _board);
    switch (vresult.first) {
        case Action::ValidationResult::ILLEGAL:
            env.utilities.logger.info(std::string(vresult.second)); // TODO: fix this
            break;
        default:
            env.utilities.logger.info("good move buddy");
            break;
    }
}

void Game::print(std::ostream& os) const {
    _board.print(os);
}

