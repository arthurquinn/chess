#include "commands/move_piece.h"
#include "entities/chess.h"

void MovePiece::run(Chess& chess) const {
    chess.move_piece(_src, _dest);
}
