#ifndef __CASTLE_VISITOR_H
#define __CASTLE_VISITOR_H

#include "interfaces/visitors/piece_visitor.h"

class CastleVisitor : public PieceVisitor {
private:

public:
    CastleVisitor() = default;
    virtual ~CastleVisitor() = default;

    virtual void visit(const Bishop& piece) const override;
    virtual void visit(const King& piece) const override;
    virtual void visit(const Knight& piece) const override;
    virtual void visit(const Pawn& piece) const override;
    virtual void visit(const Queen& piece) const override;
    virtual void visit(const Rook& piece) const override;
};

#endif
