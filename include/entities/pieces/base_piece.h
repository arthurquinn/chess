#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>

#include "interfaces/printable.h"

class Board;

class BasePiece : public Printable {
public:
    using Location = std::pair<const unsigned char, const unsigned char>;
    enum class PieceColor {
        BLACK,
        WHITE
    };

protected:
    PieceColor _color;
    Location _location;

    inline char color_char() const {
        return _color == PieceColor::WHITE ? 'w' : 'b';
    }

    bool in_bounds(const int x, const int y) const;

    void check_path(const Board& board, std::vector<Location>& locs, int x, int y, const int dx, const int dy) const;
    void check_diagonals(const Board& board, std::vector<Location>& locs) const;
    void check_across(const Board& board, std::vector<Location>& locs) const;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;

    virtual void print(std::ostream& os) const = 0;
};


#endif
