#include "actions/query_moves.h"

#include "entities/board.h"
#include "entities/player.h"

using ValidationResponse = Action::ValidationResponse;
using ActionResponse = Action::ActionResponse;

QueryMoves::QueryMoves(const Location qloc) : _qloc(qloc) {

}

ValidationResponse QueryMoves::validate(const Player& player, const Board& board) const {
    (void)player;
    (void)board;

    return std::make_pair(ValidationResult::ILLEGAL, "");
}

ActionResponse QueryMoves::run(Player& player, Board& board) const {
    (void)board;
    (void)player;

    return std::make_pair(ActionResult::SUCCESS, "");
}
