#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <memory>

class Action;

class Controller {
private:

public:
    Controller() = default;
    virtual ~Controller() = default;

    virtual std::unique_ptr<Action> get() = 0;
};

#endif
