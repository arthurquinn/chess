#include "actions/move_piece.h"

#include "entities/board.h"
#include "entities/player.h"

#include <algorithm>

using ActionResponse = Action::ActionResponse;
using ValidationResponse = Action::ValidationResponse;

MovePiece::MovePiece(const Location from, const Location to) : _from(from), _to(to) {

}

ValidationResponse MovePiece::validate(const Player& player, const Board& board) const {
    const auto& fpiece = board.at(_from);

    if (fpiece == nullptr) {
        return std::make_pair(ValidationResult::ILLEGAL, "No piece at source location");
    }

    if (!player.owns_piece(*fpiece)) {
        return std::make_pair(ValidationResult::ILLEGAL, "Player does not own this piece");
    }
    
    const auto moves = fpiece->possible_moves(board);
    if (std::find(moves.cbegin(), moves.cend(), _to) == moves.cend()) {
        return std::make_pair(ValidationResult::ILLEGAL, "This move is not valid");
    }

    return std::make_pair(ValidationResult::LEGAL, "");
}

ActionResponse MovePiece::run(const Player& player, const Board& board) const {
    (void)player;
    (void)board;

    return std::make_pair(ActionResult::SUCCESS, "");
}

