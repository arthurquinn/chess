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

public:
    BasePiece() = delete;
    BasePiece(const Color color, const Location& location) :
            _color(color),
            _location(location) { }

    virtual ~BasePiece() = default;

    virtual std::vector<Location> possible_moves(const Board& board) const = 0;
};

#endif
