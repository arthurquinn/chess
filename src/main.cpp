#include <cstdlib>
#include <iostream>

#include "utilities/logger.h"
#include "graphics/window.h"

#include "entities/board.h"


int main(int argc, char **argv) {

    Logger logger;
    logger.set_ostream(&std::cout);

    (void)argc;
    (void)argv;

    // auto window = Window();
    // window.test();

    logger.debug("debug");
    logger.info("info");
    logger.warn("warn");
    logger.error("error");
    logger.fatal("fatal");

    Board board;

    board.setup();
    board.print(std::cout);

    return EXIT_SUCCESS;
}

