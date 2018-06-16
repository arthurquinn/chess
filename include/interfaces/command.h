#ifndef __COMMAND_H
#define __COMMAND_H

class Chess;

class Command {
public:
    Command() = default;
    virtual ~Command() = default;

    virtual void run(Chess& chess) const = 0;
};

#endif
