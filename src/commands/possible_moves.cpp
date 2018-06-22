#include "commands/possible_moves.h"
#include "entities/chess.h"

void PossibleMoves::run(Chess& chess) const {
    chess.possible_moves(_query);
}
