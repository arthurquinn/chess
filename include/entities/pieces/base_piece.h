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
    using Location = Board::Location;
    PieceColor _color;
    Location _location;

    inline const bool in_bounds(const int x, const int y) const {
        return x - Board::BOARD_DIM < 0 && y - Board::BOARD_DIM < 0;
    }

    const std::vector<Location> check_diagonals(const Board& board) const;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;

};


#endif
