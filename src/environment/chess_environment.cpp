#include "environment/chess_environment.h"

#include <iostream>

namespace ChessEnv {
    ChessEnvironment env;
}

void ChessEnvironment::initialize() {
    utilities.logger.set_ostream(&std::cout);
}

void ChessEnvironment::terminate() {

}
