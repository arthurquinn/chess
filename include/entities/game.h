#ifndef __GAME_H
#define __GAME_H

#include <map>

#include "entities/board.h"
#include "entities/player.h"

class Game {
private:
    using PlayerColor = BasePiece::PieceColor;
    using PlayerMap = std::map<PlayerColor, Player>;

    enum class GameState {
        EMPTY,
        READY,
        RUNNING,
        COMPLETE
    };

    GameState _state = GameState::EMPTY;

    Board _board;
    PlayerMap _players;

    PlayerColor _turn_color;

    // Return the color of the player's whose turn it currently is, then cycle to the color of the next player
    PlayerColor cycle(const PlayerColor color);

public:
    Game() = default;
    virtual ~Game() = default;

    void setup();

    void run();

    void reset();
};

#endif
