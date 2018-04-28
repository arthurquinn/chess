#include "entities/game.h"
#include "environment/chess_environment.h"
#include "interfaces/action.h"

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

void Game::action_run(const Action& action) {
    env.utilities.logger.debug("running action");

    const auto& res = action.run(_players.at(_turn_color), _board);
    switch (res) {
        case Action::ActionResult::FAILURE:
            env.utilities.logger.error("ran invalid action; should have been caught by validate action");
            break;
        case Action::ActionResult::SUCCESS_SAME_TURN:
            env.utilities.logger.debug("action ran; same players turn");
            break;
        case Action::ActionResult::SUCCESS_TURN_COMPLETE:
            env.utilities.logger.debug("action ran; switching turns");
            shift_turn();
            break;
        default:
            env.utilities.logger.error("invalid action result");
    }
}

void Game::action_run_if_valid(const Action& action) {
    env.utilities.logger.debug("validating action");

    const auto& res = action.validate(_players.at(_turn_color), _board);
    switch (res) {
        case Action::ValidationResult::ILLEGAL_MOVE:
            env.utilities.logger.debug("move not allowed");
            break;
        case Action::ValidationResult::ILLEGAL_NULL_PIECE:
            env.utilities.logger.debug("no piece at location");
            break;
        case Action::ValidationResult::ILLEGAL_PLAYER_OWNERSHIP:
            env.utilities.logger.debug("player does not own this piece");
            break;
        case Action::ValidationResult::LEGAL:
            action_run(action);
            break;
        default:
            env.utilities.logger.error("invalid validation result");
            break;
    }
}

void Game::setup() {
    _board.setup();
    _players.emplace(PlayerColor::WHITE, PlayerColor::WHITE);
    _players.emplace(PlayerColor::BLACK, PlayerColor::BLACK);
    _turn_color = PlayerColor::WHITE;
    _state = GameState::READY;
}

void Game::reset() {
    _board.clear();
    _players.clear();
    _turn_color = PlayerColor::INVALID;
    _state = GameState::EMPTY;
}

void Game::act(const Action& action) {
    env.utilities.logger.debug("game received action");

    action_run_if_valid(action);
}

void Game::print(std::ostream& os) const {
    _board.print(os);
}

