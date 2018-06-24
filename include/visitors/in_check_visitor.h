#ifndef __IN_CHECK_VISITOR_H
#define __IN_CHECK_VISITOR_H

#include "interfaces/visitors/piece_visitor.h"
#include "interfaces/piece.h"

class InCheckVisitor : public PieceVisitor {
public:
    using Color = Piece::Color;

    enum class InCheckState {
        UNDETERMINED,
        KING_IN_CHECK,
        KING_NOT_IN_CHECK
    };

private:
    const Board& _board;
    const Color _color;

    InCheckState _in_check_state { InCheckState::UNDETERMINED };

public:
    InCheckVisitor() = delete;
    InCheckVisitor(const Board& board, const Color color) :
            _board(board), _color(color) {  }

    virtual ~InCheckVisitor() = default;

    virtual void visit(const Bishop& piece) override;
    virtual void visit(const King& piece) override;
    virtual void visit(const Knight& piece) override;
    virtual void visit(const Pawn& piece) override;
    virtual void visit(const Queen& piece) override;
    virtual void visit(const Rook& piece) override;

    inline InCheckState in_check_state() const { return _in_check_state; }
};

#endif
