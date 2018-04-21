#include <cstdlib>
#include <iostream>

#include "graphics/window.h"
#include "entities/game.h"
#include "controllers/keyboard.cpp"

#include "environment/chess_environment.h"

using namespace ChessEnv;

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    env.initialize();

    Game game;
    game.setup();

    Keyboard keyboard;

    while (game.active()) {
        game.act(*(keyboard.get()));
    }

    env.terminate();
    return EXIT_SUCCESS;
}

