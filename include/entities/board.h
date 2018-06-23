#ifndef __BOARD_H
#define __BOARD_H

#include "interfaces/piece.h"
#include "interfaces/printable.h"
#include "conceptual/location.h"

#include <memory>
#include <array>

class PieceVisitor;

class Board : public Printable {
public:
    using Color = Piece::Color;

private:
    static const int BOARD_DIM = 8;

    using BoardData = std::unique_ptr<Piece>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    BoardGrid _board;

    void create_minor_row(const Color color, const int rank);
    void create_major_row(const Color color, const int rank);

public:
    Board();
    virtual ~Board();

    Board(const Board& rhs);
    Board& operator=(const Board& rhs);

    Board(Board&& move) = delete;
    Board& operator=(Board&& move) = delete;

    inline bool in_bounds(const int rank, const int file) const {
        return rank >= 0 && rank <= 7 && file >= 0 && file <= 7;
    }

    inline bool in_bounds(const Location& location) const {
        return in_bounds(location.rank(), location.file());
    }

    inline bool empty(const int rank, const int file) const {
        return _board.at(rank).at(file) == nullptr;
    }

    inline bool empty(const Location& location) const {
        return empty(location.rank(), location.file());
    }

    inline bool occupied(const int rank, const int file) const {
        return !empty(rank, file);
    }

    inline bool occupied(const Location& location) const {
        return !empty(location);
    }

    inline const Piece& at(const int rank, const int file) const {
        return *_board.at(rank).at(file);
    }

    inline const Piece& at(const Location& location) const {
        return at(location.rank(), location.file());
    }

    void setup();

    void clear();

    void move(const Location& src, const Location& dest);

    void visit_pieces(PieceVisitor& visitor) const;

    virtual void print(std::ostream& os) const override;
};

#endif
