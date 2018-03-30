#include "factories/piece_factory.h"

#include "entities/pieces/pawn.h"
#include "entities/pieces/rook.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/king.h"

// TODO: Do we really need a factory...?

const std::shared_ptr<Pawn> PieceFactory::createPawn(const BasePiece::PieceColor color) const {
    return std::make_shared<Pawn>(color);
}

const std::shared_ptr<Rook> PieceFactory::createRook(const BasePiece::PieceColor color) const {
    return std::make_shared<Rook>(color);
}

const std::shared_ptr<Bishop> PieceFactory::createBishop(const BasePiece::PieceColor color) const {
    return std::make_shared<Bishop>(color);
}

const std::shared_ptr<Knight> PieceFactory::createKnight(const BasePiece::PieceColor color) const {
    return std::make_shared<Knight>(color);
}

const std::shared_ptr<Queen> PieceFactory::createQueen(const BasePiece::PieceColor color) const {
    return std::make_shared<Queen>(color);
}

const std::shared_ptr<King> PieceFactory::createKing(const BasePiece::PieceColor color) const {
    return std::make_shared<King>(color);
}