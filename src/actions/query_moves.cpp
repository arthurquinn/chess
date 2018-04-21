#include "actions/query_moves.h"

#include "entities/game.h"
#include "entities/board.h"

using ValidationResponse = Action::ValidationResponse;
using ActionResponse = Action::ActionResponse;

QueryMoves::QueryMoves(const Location qloc) : _qloc(qloc) {

}

ValidationResponse QueryMoves::validate(const Game& game) const {
    (void)game;

    return std::make_pair(ValidationResult::ILLEGAL, "");
}

ActionResponse QueryMoves::run(const Board& board) const {
    (void)board;

    return std::make_pair(ActionResult::SUCCESS, "");
}
