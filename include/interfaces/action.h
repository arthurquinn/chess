#ifndef __ACTION_H
#define __ACTION_H


class Action {
private:

public:
    Action() = default;
    virtual ~Action() = default;

    virtual void run() const = 0;
};

#endif
