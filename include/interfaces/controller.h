#ifndef __CONTROLLER_H
#define __CONTROLLER_H

class Action;

class Controller {
private:

public:
    Controller() = default;
    virtual ~Controller() = default;

    virtual Action get() = 0;
};

#endif
