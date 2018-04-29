#ifndef __GAME_H
#define __GAME_H

#include <map>
#include <memory>

#include "entities/board.h"
#include "interfaces/printable.h"
#include "entities/player.h"

class Action;

class Game : public Printable {
public:
    using PlayerColor = BasePiece::PieceColor;
private:
    using PlayerMap = std::map<PlayerColor, Player>;

    using PlayerKing = std::shared_ptr<King>;
    using PlayerKingMap = std::map<PlayerColor, PlayerKing>;

    using GamePiece = std::shared_ptr<BasePiece>;
    using GamePieces = std::vector<GamePiece>; // TODO: this can be an array

    enum class GameState {
        EMPTY,
        READY,
        RUNNING,
        COMPLETE
    };

    GameState _state { GameState::EMPTY };
    PlayerColor _turn_color { PlayerColor::INVALID };

    GamePieces _pieces;
    PlayerKingMap _kings;

    Board _board;
    PlayerMap _players;

    void shift_turn();

    GamePieces create_minor_row(const PlayerColor color) const;
    GamePieces create_major_row(const PlayerColor color) const;
    GamePieces create_pieces_for_color(const PlayerColor color) const;
    PlayerKing create_king_for_color(const PlayerColor color) const;

public:
    Game() = default;
    virtual ~Game() = default;

    Game(const Game& game) = default;
    Game& operator=(const Game& game) = default; // TODO: implement these

    Game(Game&& game) = delete;
    Game& operator=(Game&& game) = delete;

    bool active() const;

    std::unique_ptr<Game> setup() const;

    std::unique_ptr<Game> reset() const;

    std::unique_ptr<Game> act(const Action& action) const;

    virtual void print(std::ostream& os) const override;
};

#endif
