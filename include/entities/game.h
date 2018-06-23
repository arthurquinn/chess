#ifndef __GAME_H
#define __GAME_H

#include <memory>

class Controller;

class Game {
private:
    std::unique_ptr<Controller> _controller;

public:
    Game();
    virtual ~Game();

    void initialize();
    void run() const;
};

#endif
