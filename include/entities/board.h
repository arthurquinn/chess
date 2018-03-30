#ifndef __BOARD_H
#define __BOARD_H

#include <array>
#include <memory>
#include <experimental/optional>

class BasePiece;

class Board {
public:
    static const unsigned char BOARD_DIM = 8;
private:
    using BoardData = std::experimental::optional<std::unique_ptr<BasePiece>>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    BoardGrid _board;

public:
    using Location = std::pair<const unsigned char, const unsigned char>;

    Board() = default;
    virtual ~Board() = default;

    const BoardData& at(const int x, const int y) const;
    const BoardData& at(const Location location) const;
};


#endif
