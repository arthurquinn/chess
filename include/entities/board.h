#ifndef __BOARD_H
#define __BOARD_H

#include <memory>
#include <array>

class BasePiece;

class Board {
private:
    static const int BOARD_DIM = 8;

    using BoardData = std::unique_ptr<BasePiece>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    BoardGrid _board;

public:
    Board();
    virtual ~Board();

    Board(const Board& copy) = delete;
    Board& operator=(const Board& copy) = delete;

    Board(Board&& move) = delete;
    Board& operator=(Board&& move) = delete;

    void setup();

    void clear();

    
};

#endif
