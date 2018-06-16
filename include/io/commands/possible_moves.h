#ifndef __POSSIBLE_MOVES_H
#define __POSSIBLE_MOVES_H

#include "entities/pieces/base_piece.h"
#include "interfaces/command.h"

class PossibleMoves : public Command {
public:
    using Location = BasePiece::Location;

private:
    Location _query;

public:
    PossibleMoves() = delete;
    PossibleMoves(const Location& query) :
            _query(query) {  }

    virtual ~PossibleMoves() = default;

    virtual void run(Chess& chess) const override;
};

#endif
