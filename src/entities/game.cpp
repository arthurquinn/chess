#include "entities/game.h"


void Game::setup() {
    _board.setup();
    _players.emplace(PlayerColor::WHITE, PlayerColor::WHITE);
    _players.emplace(PlayerColor::BLACK, PlayerColor::BLACK);
    _state = GameState::READY;
}

void Game::run() {
    if (_state == GameState::READY) {
        _state = GameState::RUNNING;
        while (_state == GameState::RUNNING) {

        }
    }
}

void Game::reset() {
    _board.clear();
    _players.clear();
    _state = GameState::EMPTY;
}

