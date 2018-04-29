#include "actions/move_piece.h"

#include "entities/board.h"
#include "entities/player.h"

#include <algorithm>

using ValidationResult = Action::ValidationResult;
using ActionResult = Action::ActionResult;

MovePiece::MovePiece(const Location from, const Location to) : _from(from), _to(to) {

}

ValidationResult MovePiece::validate(const Player& player, const Board& board) const {
    const auto& fpiece = board.at(_from);

    if (fpiece == nullptr) {
        return ValidationResult::ILLEGAL_NULL_PIECE;
    }

    (void)player;
    // if (!player.owns_piece(*fpiece)) {
    //     return ValidationResult::ILLEGAL_PLAYER_OWNERSHIP;
    // }
    
    const auto moves = fpiece->possible_moves(board);
    if (std::find(moves.cbegin(), moves.cend(), _to) == moves.cend()) {
        return ValidationResult::ILLEGAL_MOVE;
    }

    return ValidationResult::LEGAL;
}

ActionResult MovePiece::run(Player& player, Board& board) const {
    (void)player;


    board.move(_from, _to);
    return ActionResult::SUCCESS_TURN_COMPLETE;
}

