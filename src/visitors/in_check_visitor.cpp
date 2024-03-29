#include "visitors/in_check_visitor.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/king.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/pawn.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/rook.h"

#include <algorithm>

void InCheckVisitor::visit(const Bishop& piece) {
    (void)piece;
}

void InCheckVisitor::visit(const King& piece) {
    if (piece.is_allied(_color)) {
        if (piece.in_check(_board)) {
            _in_check_state = InCheckState::KING_IN_CHECK;
        } else {
            _in_check_state = InCheckState::KING_NOT_IN_CHECK;
        }
    }
}

void InCheckVisitor::visit(const Knight& piece) {
    (void)piece;
}

void InCheckVisitor::visit(const Pawn& piece) {
    (void)piece;
}

void InCheckVisitor::visit(const Queen& piece) {
    (void)piece;
}

void InCheckVisitor::visit(const Rook& piece) {
    (void)piece;
}
