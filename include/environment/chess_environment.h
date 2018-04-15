#ifndef __CHESS_ENVIRONMENT_H
#define __CHESS_ENVIRONMENT_H

#include "utilities/logger.h"

class ChessEnvironment {
private:

public:
    struct _utilities {
        Logger logger;
    } utilities;

    ChessEnvironment() = default;
    virtual ~ChessEnvironment() = default;

    void initialize();
    void terminate();
};

namespace ChessEnv {
    extern ChessEnvironment env;
}

#endif
