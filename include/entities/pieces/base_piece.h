#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>

class Board;

class BasePiece {
public:
    enum class PieceColor {
        BLACK,
        WHITE
    };

protected:
    using Location = std::pair<unsigned char, unsigned char>;
    PieceColor _color;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;
};


#endif
