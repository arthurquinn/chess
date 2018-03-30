#ifndef __BOARD_H
#define __BOARD_H

#include <array>
#include <memory>
#include <experimental/optional>

#include "entities/pieces/base_piece.h"

class Board {
public:
    static const unsigned char BOARD_DIM = 8;
private:
    using BoardData = std::experimental::optional<std::unique_ptr<BasePiece>>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    BoardGrid _board;

public:
    using Location = BasePiece::Location;

    Board() = default;
    virtual ~Board() = default;

    const BoardData& at(const int x, const int y) const;
    const BoardData& at(const Location location) const;
};


#endif
