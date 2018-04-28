#ifndef __BOARD_H
#define __BOARD_H

#include <array>
#include <memory>

#include "interfaces/printable.h"
#include "entities/pieces/base_piece.h"

class PieceFactory;
class Player;

class Board : public Printable {
public:
    static const int BOARD_DIM { 8 };

    using PieceColor = BasePiece::PieceColor;
    using Location = BasePiece::Location;

    using BoardData = std::shared_ptr<BasePiece>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

private:
    BoardGrid _board;

public:
    Board() = default;
    virtual ~Board() = default;

    bool in_bounds(const int r, const int f) const;
    bool in_bounds(const Location& location) const;

    bool empty(const int r, const int f) const;
    bool empty(const Location& location) const;

    const BoardData& at(const int r, const int f) const;
    const BoardData& at(const Location& location) const;

    void place(const BoardData& bd, const Location& location);
    void place(const BoardData& bd, const int r, const int f);

    void move(const int sr, const int sf, const int tr, const int tf);
    void move(const Location& sloc, const Location& tloc);

    void clear();

    virtual void print(std::ostream& os) const override;
};


#endif
