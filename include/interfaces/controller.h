#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <memory>

class Command;

class Controller {
public:
    Controller() = default;
    virtual ~Controller() = default;

    virtual std::unique_ptr<Command> getCommand() const = 0;
};

#endif
