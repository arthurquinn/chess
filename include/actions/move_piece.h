#ifndef __MOVE_PIECE_H
#define __MOVE_PIECE_H

#include "interfaces/action.h"
#include "entities/pieces/base_piece.h"

class MovePiece : public Action {
public:
    using Location = BasePiece::Location;

private:
    const Location _from;
    const Location _to;

public:
    MovePiece() = delete;
    MovePiece(const Location from, const Location to);

    virtual ~MovePiece() = default;

    ValidationResult validate(const Player& player, const Board& board) const override;
    ActionResult run(Player& player, Board& board) const override;
};

#endif
