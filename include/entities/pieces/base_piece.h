#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>

class Board;

class BasePiece {
public:
    using Location = std::pair<const unsigned char, const unsigned char>;
    enum class PieceColor {
        BLACK,
        WHITE
    };

protected:
    PieceColor _color;
    Location _location;

    const bool in_bounds(const int x, const int y) const;

    const std::vector<Location> check_diagonals(const Board& board) const;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;

};


#endif
