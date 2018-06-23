#include "entities/game.h"
#include "io/keyboard.h"
#include "interfaces/command.h"

#include <iostream>

Game::Game() = default;
Game::~Game() = default;

void Game::initialize() {
    _controller = std::make_unique<Keyboard>();

}

void Game::run() const {


}
