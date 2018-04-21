#include "factories/piece_factory.h"

#include "entities/pieces/pawn.h"
#include "entities/pieces/rook.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/king.h"

// TODO: Do we really need a factory...?

std::unique_ptr<BasePiece> PieceFactory::createPawn(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<Pawn>(color, x, y);
}

std::unique_ptr<BasePiece> PieceFactory::createRook(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<Rook>(color, x, y);
}

std::unique_ptr<BasePiece> PieceFactory::createBishop(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<Bishop>(color, x, y);
}

std::unique_ptr<BasePiece> PieceFactory::createKnight(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<Knight>(color, x, y);
}

std::unique_ptr<BasePiece> PieceFactory::createQueen(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<Queen>(color, x, y);
}

std::unique_ptr<BasePiece> PieceFactory::createKing(const BasePiece::PieceColor color, const int x, const int y) const {
    return std::make_unique<King>(color, x, y);
}