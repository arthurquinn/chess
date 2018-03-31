#ifndef __BOARD_H
#define __BOARD_H

#include <array>
#include <memory>

#include "entities/pieces/base_piece.h"

class PieceFactory;

class Board {
public:
    static const unsigned char BOARD_DIM = 8;
private:
    using BoardData = std::unique_ptr<BasePiece>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    using PieceColor = BasePiece::PieceColor;

    BoardGrid _board;

    void create_minor_row(const PieceFactory& pf, const unsigned char row, const PieceColor color);
    void create_major_row(const PieceFactory& pf, const unsigned char row, const PieceColor color);

public:
    using Location = BasePiece::Location;

    Board() = default;
    virtual ~Board() = default;

    // Disable copy (we contain unique pointers -- implement deep copy if this is wanted in the future)
    Board(const Board& copy) = delete;
    Board& operator=(const Board& copy) = delete;

    // Disable move (this can be added later)
    Board(Board&& move) = delete;
    Board& operator=(Board&& move) = delete;

    const BoardData& at(const int x, const int y) const;
    const BoardData& at(const Location location) const;

    void clear();
    void setup();
};


#endif
