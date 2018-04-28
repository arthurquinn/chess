#ifndef __PIECE_FACTORY_H
#define __PIECE_FACTORY_H

#include <memory>
#include "entities/pieces/base_piece.h"

class PieceFactory {
private:

public:
    PieceFactory() = default;
    virtual ~PieceFactory() = default;

    std::shared_ptr<BasePiece> createPawn(const BasePiece::PieceColor color, const int x, const int y) const;
    std::shared_ptr<BasePiece> createRook(const BasePiece::PieceColor color, const int x, const int y) const;
    std::shared_ptr<BasePiece> createBishop(const BasePiece::PieceColor color, const int x, const int y) const;
    std::shared_ptr<BasePiece> createKnight(const BasePiece::PieceColor color, const int x, const int y) const;
    std::shared_ptr<BasePiece> createQueen(const BasePiece::PieceColor color, const int x, const int y) const;
    std::shared_ptr<BasePiece> createKing(const BasePiece::PieceColor color, const int x, const int y) const;
};


#endif
