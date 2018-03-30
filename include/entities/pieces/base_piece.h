#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>

#include "entities/board.h"

class BasePiece {
public:
    enum class PieceColor {
        BLACK,
        WHITE
    };

protected:
    PieceColor _color;
    using Location = Board::Location;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;
};


#endif
