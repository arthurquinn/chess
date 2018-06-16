#include "entities/game.h"
#include "entities/chess.h"
#include "io/keyboard.h"
#include "interfaces/command.h"

#include <iostream>

Game::Game() = default;
Game::~Game() = default;

void Game::initialize() {
    _controller = std::make_unique<Keyboard>();
    _chess = std::make_unique<Chess>();

    _chess->initialize();
}

void Game::run() const {

    _chess->print(std::cout);
    // TODO: implement interrupt mechanism
    for (;;) {
        _controller->getCommand()->run(*_chess);
        _chess->print(std::cout);
    }
}
