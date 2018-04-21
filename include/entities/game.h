#ifndef __GAME_H
#define __GAME_H

#include <map>

#include "entities/board.h"
#include "entities/player.h"
#include "interfaces/action.h"
#include "interfaces/printable.h"

class Game : public Printable {
public:
    using PlayerColor = BasePiece::PieceColor;
private:
    using PlayerMap = std::map<PlayerColor, Player>;

    enum class GameState {
        EMPTY,
        READY,
        RUNNING,
        COMPLETE
    };

    GameState _state { GameState::EMPTY };

    Board _board;
    PlayerMap _players;

    PlayerColor _turn_color;

    // Return the color of the player's whose turn it currently is, then cycle to the color of the next player
    PlayerColor cycle(const PlayerColor color);

public:
    Game() = default;
    virtual ~Game() = default;

    inline bool active() const {
        return _state == GameState::READY || _state == GameState::RUNNING;
    }

    void setup();

    void reset();

    void act(const Action& action);

    virtual void print(std::ostream& os) const override;
};

#endif
