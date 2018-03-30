#ifndef __PIECE_FACTORY_H
#define __PIECE_FACTORY_H

#include <memory>
#include "pieces/base_piece.h"

class Pawn;
class Rook;
class Bishop;
class Knight;
class Queen;
class King;

class PieceFactory {
private:

public:
    PieceFactory() = default;
    virtual ~PieceFactory() = default;

    const std::shared_ptr<Pawn> createPawn(const BasePiece::PieceColor color) const;
    const std::shared_ptr<Rook> createRook(const BasePiece::PieceColor color) const;
    const std::shared_ptr<Bishop> createBishop(const BasePiece::PieceColor color) const;
    const std::shared_ptr<Knight> createKnight(const BasePiece::PieceColor color) const;
    const std::shared_ptr<Queen> createQueen(const BasePiece::PieceColor color) const;
    const std::shared_ptr<King> createKing(const BasePiece::PieceColor color) const;
};


#endif
