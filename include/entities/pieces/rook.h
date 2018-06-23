#ifndef __ROOK_H
#define __ROOK_H

#include "entities/pieces/base_piece.h"

#include <vector>

class Board;

class Rook : public BasePiece {
public:
    using Color = BasePiece::Color;

    enum class CastleState {
        CANNOT_CASTLE,
        IN_POSITION_QUEENSIDE,
        IN_POSITION_KINGSIDE
    };

private:
    static const unsigned int KINGSIDE_FILE = 7;
    static const unsigned int QUEENSIDE_FILE = 0;

    bool _was_moved { false };

public:
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

    unsigned int starting_rank() const;

    inline bool is_kingside() const {
        return !_was_moved && _location.rank() == starting_rank() && _location.file() == KINGSIDE_FILE;
    }

    inline bool is_queenside() const {
        return !_was_moved && _location.rank() == starting_rank() && _location.file() == QUEENSIDE_FILE;
    }

    CastleState castle_state() const;
};

#endif
