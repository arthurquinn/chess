#ifndef __CHESS_H
#define __CHESS_H

#include "entities/board.h"
#include "interfaces/piece.h"
#include "interfaces/printable.h"

class Chess : public Printable {
private:
    using Color = Piece::Color;
    using Location = Piece::Location;

    Color _turn_color { Color::INVALID };
    Board _board;

    static Color adversarial_color(const Color other);

public:
    Chess() = default;
    virtual ~Chess() = default;

    void initialize();

    // TODO: eventually these should return results to the calling commands
    //          and not output to stdout
    void move_piece(const Location& src, const Location& dest);
    void possible_moves(const Location& query) const;

    virtual void print(std::ostream& os) const override;
};

#endif
