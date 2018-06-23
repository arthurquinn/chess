#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Rook : public BasePiece {
public:
    enum class CastleState {
        CAN_CASTLE_QUEENSIDE,
        CAN_CASTLE_KINGSIDE,
        CANNOT_CASTLE
    };

private:
    bool _was_moved { false };

    CastleState check_black_castle() const;
    CastleState check_white_castle() const;

public:
    using Color = BasePiece::Color;

    Rook() = delete;
    Rook(const Color color, const Location& location) :
            BasePiece(color, location) {  }

    virtual ~Rook() = default;

    inline virtual void move(const Location& dest) override {
        BasePiece::move(dest);
        _was_moved = true;
    }

    virtual vec_uptr<Move> possible_moves_no_check(const Board& board) const override;

    virtual std::unique_ptr<Piece> clone() const override;

    virtual void print(std::ostream& os) const override;

    virtual void accept(PieceVisitor& visitor) const override;

    CastleState castle_state() const;
};

#endif
