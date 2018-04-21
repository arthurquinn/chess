#include "actions/move_piece.h"

#include "entities/game.h"
#include "entities/board.h"

using ActionResponse = Action::ActionResponse;
using ValidationResponse = Action::ValidationResponse;

MovePiece::MovePiece(const Location from, const Location to) : _from(from), _to(to) {

}

ValidationResponse MovePiece::validate(const Game& game) const {
    (void)game;

    return std::make_pair(ValidationResult::ILLEGAL, "");
}

ActionResponse MovePiece::run(const Board& board) const {
    (void)board;

    return std::make_pair(ActionResult::SUCCESS, "");
}

