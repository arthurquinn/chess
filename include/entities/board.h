#ifndef __BOARD_H
#define __BOARD_H

#include <array>
#include <memory>

#include "interfaces/printable.h"
#include "entities/pieces/base_piece.h"

class PieceFactory;

class Board : public Printable {
public:
    static const int BOARD_DIM { 8 };
private:
    using BoardData = std::shared_ptr<BasePiece>;
    using BoardRow = std::array<BoardData, BOARD_DIM>;
    using BoardGrid = std::array<BoardRow, BOARD_DIM>;

    using PieceColor = BasePiece::PieceColor;

    BoardGrid _board;

    void create_minor_row(const PieceFactory& pf, const int row, const PieceColor color);
    void create_major_row(const PieceFactory& pf, const int row, const PieceColor color);

public:
    using Location = BasePiece::Location;

    Board() = default;
    virtual ~Board() = default;

    bool pre_check(const Location& from, const Location& to) const;

    bool in_bounds(const int r, const int f) const;
    bool in_bounds(const Location& location) const;

    bool empty(const int r, const int f) const;
    bool empty(const Location& location) const;

    const BoardData& at(const int r, const int f) const;
    const BoardData& at(const Location& location) const;

    void move(const int sr, const int sf, const int tr, const int tf);
    void move(const Location& sloc, const Location& tloc);

    void clear();
    void setup();

    virtual void print(std::ostream& os) const override;
};


#endif
