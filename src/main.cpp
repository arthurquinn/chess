#include <cstdlib>

#include "graphics/window.h"

int main(int argc, char **argv) {

    (void)argc;
    (void)argv;

    auto window = Window();
    window.test();

    return EXIT_SUCCESS;
}

