#ifndef __PIECE_VISITOR_H
#define __PIECE_VISITOR_H

class Bishop;
class King;
class Knight;
class Pawn;
class Queen;
class Rook;

class PieceVisitor {
public:
    PieceVisitor() = default;
    virtual ~PieceVisitor() = default;

    virtual void visit(const Bishop& piece) const = 0;
    virtual void visit(const King& piece) const = 0;
    virtual void visit(const Knight& piece) const = 0;
    virtual void visit(const Pawn& piece) const = 0;
    virtual void visit(const Queen& piece) const = 0;
    virtual void visit(const Rook& piece) const = 0;
};

#endif
