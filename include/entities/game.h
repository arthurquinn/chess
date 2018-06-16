#ifndef __GAME_H
#define __GAME_H

#include <memory>

class Chess;
class Controller;

class Game {
private:
    std::unique_ptr<Controller> _controller;
    std::unique_ptr<Chess> _chess; // TODO: eventually make interface around Chess class

public:
    Game();
    virtual ~Game();

    void initialize();
    void run() const;
};

#endif
