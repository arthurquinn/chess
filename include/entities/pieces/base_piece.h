#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include "interfaces/cloneable.h"
#include "interfaces/printable.h"
#include "interfaces/piece.h"

#include <utility>
#include <vector>

class Board;

class BasePiece : public Piece {
public:
    using Color = Piece::Color;
    using Location = Piece::Location;

protected:
    Color _color;
    Location _location;

    std::vector<Location> check_path(const Board& board, const int dr, const int df) const;
    std::vector<Location> check_diagonals(const Board& board) const;
    std::vector<Location> check_across(const Board& board) const;

    bool can_move(const Board& board, const int rank, const int file) const;
    bool can_move(const Board& board, const Location& dest) const;

    inline void common_print(std::ostream& os, const char piece_char) const {
        os << (_color == Color::WHITE ? "w" : "b") << piece_char;
    }

public:
    BasePiece() = delete;
    BasePiece(const Color color, const Location& location) :
            _color(color),
            _location(location) { }

    virtual ~BasePiece() = default;

    inline virtual void move(const Location& dest) override { _location = dest; }

    inline virtual Color color() const override { return _color; }

    std::vector<Location> possible_moves(const Board& board) const override;
};

#endif
