#include "visitors/in_check_visitor.h"
#include "entities/pieces/bishop.h"
#include "entities/pieces/king.h"
#include "entities/pieces/knight.h"
#include "entities/pieces/pawn.h"
#include "entities/pieces/queen.h"
#include "entities/pieces/rook.h"

#include <algorithm>

void InCheckVisitor::visit(const Bishop& piece) {

}

void InCheckVisitor::visit(const King& piece) {
    if (piece.is_allied(_color)) {
        
    }
}

void InCheckVisitor::visit(const Knight& piece) {

}

void InCheckVisitor::visit(const Pawn& piece) {

}

void InCheckVisitor::visit(const Queen& piece) {

}

void InCheckVisitor::visit(const Rook& piece) {

}