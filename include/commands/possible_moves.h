#ifndef __POSSIBLE_MOVES_H
#define __POSSIBLE_MOVES_H

#include "interfaces/command.h"
#include "conceptual/location.h"

class PossibleMoves : public Command {
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
