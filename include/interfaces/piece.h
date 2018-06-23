#ifndef __PIECE_H
#define __PIECE_H

#include "interfaces/cloneable.h"
#include "interfaces/printable.h"

#include <vector>
#include <memory>

class Board;
class Move;
class PieceVisitor;
class Location;

class Piece : public Printable, public Cloneable<Piece> {
public:
    template<typename T>
    using vec_uptr = std::vector<std::unique_ptr<T>>;

    enum class Color {
        INVALID,
        WHITE,
        BLACK
    };

    Piece() = default;
    virtual ~Piece() = default;

    virtual void move(const Location& dest) = 0;

    virtual Color get_color() const = 0;

    virtual vec_uptr<Move> possible_moves(const Board& board) const = 0;
    virtual vec_uptr<Move> possible_moves_no_check(const Board& board) const = 0;

    virtual void accept(PieceVisitor& visitor) const = 0;

    // Default methods
    inline bool is_allied(const Color other) const { return get_color() == other; }
    inline bool is_adversary(const Color other) const { return !is_allied(other); }

    inline bool is_allied(const Piece& other) const { return get_color() == other.get_color(); }
    inline bool is_adversary(const Piece& other) const { return !is_allied(other); }
};

#endif
