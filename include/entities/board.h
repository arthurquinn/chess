#ifndef __BOARD_H
#define __BOARD_H

#include "entities/pieces/base_piece.h"
#include "interfaces/printable.h"

#include <memory>
#include <array>

class Board : public Printable {
public:
    using Color = BasePiece::Color;
    using Location = BasePiece::Location;

private:
    static const int BOARD_DIM = 8;

    using BoardData = std::unique_ptr<BasePiece>;
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
        return in_bounds(location.first, location.second);
    }

    inline bool empty(const int rank, const int file) const {
        return _board.at(rank).at(file) == nullptr;
    }

    inline bool empty(const Location& location) const {
        return empty(location.first, location.second);
    }

    inline bool occupied(const int rank, const int file) const {
        return !empty(rank, file);
    }

    inline bool occupied(const Location& location) const {
        return !empty(location);
    }

    inline const BasePiece& at(const int rank, const int file) const {
        return *_board.at(rank).at(file);
    }

    inline const BasePiece& at(const Location& location) const {
        return at(location.first, location.second);
    }

    void setup();

    void clear();

    void move(const Location& src, const Location& dest);

    virtual void print(std::ostream& os) const override;
};

#endif
