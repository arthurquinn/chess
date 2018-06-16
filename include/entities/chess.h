#ifndef __CHESS_H
#define __CHESS_H

#include "entities/board.h"
#include "entities/pieces/base_piece.h"
#include "interfaces/printable.h"

class Chess : public Printable {
private:
    using Color = BasePiece::Color;
    using Location = BasePiece::Location;

    Color _turn_color { Color::INVALID };
    Board _board;

public:
    Chess() = default;
    virtual ~Chess() = default;

    void initialize();

    void move_piece(const Location& src, const Location& dest);
    void possible_moves(const Location& query);

    virtual void print(std::ostream& os) const override;
};

#endif
