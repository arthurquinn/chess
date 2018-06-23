#include "visitors/castle_visitor.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/king.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/pawn.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/rook.h"

void CastleVisitor::visit(const Bishop& piece) {
    
}

void CastleVisitor::visit(const King& piece) {
    if (piece.is_allied(_color) && piece.castle_state() == King::CastleState::CAN_CASTLE) {
        _king = &piece;
    }
}

void CastleVisitor::visit(const Knight& piece) {
    
}

void CastleVisitor::visit(const Pawn& piece) {
    
}

void CastleVisitor::visit(const Queen& piece) {
    
}

void CastleVisitor::visit(const Rook& piece) {
    if (piece.is_allied(_color)) {
        switch (piece.castle_state()) {

        case Rook::CastleState::CAN_CASTLE_KINGSIDE:
            _kingside_rook = &piece;
            break;

        case Rook::CastleState::CAN_CASTLE_QUEENSIDE:
            _queenside_rook = &piece;
            break;

        default:
            break;
        }
    }
}
