#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include "interfaces/cloneable.h"
#include "interfaces/printable.h"

#include <utility>
#include <vector>

class Board;

class BasePiece : public Printable, public Cloneable<BasePiece> {
public:
    using Location = std::pair<int, int>;

    enum class Color {
        INVALID,
        BLACK,
        WHITE
    };

    static Color adversarial_color(const Color color);

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

    inline virtual void move(const Location& dest) {
        _location = dest;
    }

    inline bool is_allied(const BasePiece& other) const {
        return is_allied(other._color);
    }

    inline bool is_allied(const Color other) const {
        return _color == other;
    }

    inline bool is_adversary(const BasePiece& other) const {
        return !is_allied(other);
    }

    inline bool is_adversary(const Color other) const {
        return !is_allied(other);
    }

    std::vector<Location> possible_moves(const Board& board) const;

    virtual std::vector<Location> possible_moves_no_check(const Board& board) const = 0;

    virtual bool is_king() const = 0;
};

#endif
