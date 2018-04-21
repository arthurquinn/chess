#include "actions/move_piece.h"

#include "entities/board.h"
#include "entities/player.h"

using ActionResponse = Action::ActionResponse;
using ValidationResponse = Action::ValidationResponse;

MovePiece::MovePiece(const Location from, const Location to) : _from(from), _to(to) {

}

ValidationResponse MovePiece::validate(const Player& player, const Board& board) const {
    const auto& fpiece = board.at(_from);
    const auto& tpiece = board.at(_to);

    (void)fpiece;
    (void)tpiece;
    (void)player;

    return std::make_pair(ValidationResult::ILLEGAL, "");
}

ActionResponse MovePiece::run(const Player& player, const Board& board) const {
    (void)player;
    (void)board;

    return std::make_pair(ActionResult::SUCCESS, "");
}

