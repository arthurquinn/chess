#ifndef __PIECE_H
#define __PIECE_H

#include "interfaces/cloneable.h"
#include "interfaces/printable.h"
#include "interfaces/visitors/piece_visitor.h"

#include <vector>

class Board;

class Piece : public Printable, public Cloneable<Piece> {
public:
    using Location = std::pair<int, int>;

    enum class Color {
        INVALID,
        WHITE,
        BLACK
    };

    Piece() = default;
    virtual ~Piece() = default;

    virtual void move(const Location& dest) = 0;

    virtual Color color() const = 0;

    virtual std::vector<Location> possible_moves(const Board& board) const = 0;
    virtual std::vector<Location> possible_moves_no_check(const Board& board) const = 0;

    virtual void accept(const PieceVisitor& visitor) const = 0;

    // Default methods
    inline bool is_allied(const Color other) const { return color() == other; }
    inline bool is_adversary(const Color other) const { return !is_allied(other); }

    inline bool is_allied(const Piece& other) const { return color() == other.color(); }
    inline bool is_adversary(const Piece& other) const { return !is_allied(other); }
};

#endif
