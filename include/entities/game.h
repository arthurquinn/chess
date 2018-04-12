#ifndef __GAME_H
#define __GAME_H

#include "entities/board.h"
#include "entities/player.h"

class Game {
private:
    enum class GameState {
        EMPTY,
        READY,
        RUNNING,
        COMPLETE
    };

    GameState _state = GameState::EMPTY;

    Board _board;

    Player _wp;
    Player _bp;

    void do_turn();

public:
    Game() = default;
    virtual ~Game() = default;

    void setup();

    void run();
};

#endif
