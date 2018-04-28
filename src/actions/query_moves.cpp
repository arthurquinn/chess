#include "actions/query_moves.h"

#include "entities/board.h"
#include "entities/player.h"

using ValidationResult = Action::ValidationResult;
using ActionResult = Action::ActionResult;

QueryMoves::QueryMoves(const Location qloc) : _qloc(qloc) {

}

ValidationResult QueryMoves::validate(const Player& player, const Board& board) const {
    (void)player;
    (void)board;

    return ValidationResult::ILLEGAL_MOVE;
}

ActionResult QueryMoves::run(Player& player, Board& board) const {
    (void)board;
    (void)player;

    return ActionResult::FAILURE;
}
