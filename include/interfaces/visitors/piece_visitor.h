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

    virtual void visit(const Bishop& piece) = 0;
    virtual void visit(const King& piece) = 0;
    virtual void visit(const Knight& piece) = 0;
    virtual void visit(const Pawn& piece) = 0;
    virtual void visit(const Queen& piece) = 0;
    virtual void visit(const Rook& piece) = 0;
};

#endif
