#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>

class Board;

class BasePiece {
public:
    using Location = std::pair<int, int>;

    enum class Color {
        INVALID,
        BLACK,
        WHITE
    };

protected:
    Color _color;
    Location _location;

    std::vector<Location> check_path(const Board& board, const int dr, const int df) const;
    std::vector<Location> check_diagonals(const Board& board) const;
    std::vector<Location> check_across(const Board& board) const;

    inline bool is_opposing(const BasePiece& other) const {
        return _color != other._color;
    }

    bool can_move(const Board& board, const int rank, const int file) const;
    bool can_move(const Board& board, const Location& dest) const;

public:
    BasePiece() = delete;
    BasePiece(const Color color, const Location& location) :
            _color(color),
            _location(location) { }

    virtual ~BasePiece() = default;

    inline virtual void move(const Location& dest) {
        _location = dest;
    }

    virtual std::vector<Location> possible_moves(const Board& board) const = 0;
};

#endif
