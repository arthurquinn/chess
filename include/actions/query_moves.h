#ifndef __QUERY_MOVES_H
#define __QUERY_MOVES_H

#include "interfaces/action.h"
#include "entities/pieces/base_piece.h"

class QueryMoves : public Action {
private:
    using Location = BasePiece::Location;

    const Location _qloc;

public:
    QueryMoves() = delete;
    QueryMoves(const Location qloc);

    virtual ~QueryMoves() = default;

    ValidationResponse validate(const Player& player, const Board& board) const override;
    ActionResponse run(const Player& player, const Board& board) const override;
};

#endif
