#ifndef __BOARD_H
#define __BOARD_H

#include "entities/pieces/base_piece.h"

#include <memory>
#include <array>

class Board {
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

    Board(const Board& copy) = delete;
    Board& operator=(const Board& copy) = delete;

    Board(Board&& move) = delete;
    Board& operator=(Board&& move) = delete;

    inline bool in_bounds(const int rank, const int file) const {
        return rank >= 0 && rank <= 7 && file >= 0 && file <= 7;
    }

    inline bool empty(const int rank, const int file) const {
        return _board[rank][file] == nullptr;
    }

    void setup();

    void clear();


};

#endif
