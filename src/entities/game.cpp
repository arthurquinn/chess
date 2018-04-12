#include "entities/game.h"


void Game::setup() {
    _board.setup();
    _state = GameState::READY;
}

void Game::run() {
    if (_state == GameState::READY) {
        _state = GameState::RUNNING;
        while (_state == GameState::RUNNING) {
            do_turn();
        }
    }
}

void Game::do_turn() {

}