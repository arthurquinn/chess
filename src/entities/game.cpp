#include "entities/game.h"
#include "entities/chess.h"
#include "io/keyboard.h"
#include "interfaces/command.h"

Game::Game() = default;
Game::~Game() = default;

void Game::initialize() {
    _controller = std::make_unique<Keyboard>();
    _chess = std::make_unique<Chess>();

    _chess->initialize();
}

void Game::run() const {

    // TODO: implement interrupt mechanism
    for (;;) {
        _controller->getCommand()->run(*_chess);
    }
}
