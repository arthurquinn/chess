#ifndef __CASTLE_VISITOR_H
#define __CASTLE_VISITOR_H

#include "interfaces/visitors/piece_visitor.h"
#include "interfaces/piece.h"

class CastleVisitor : public PieceVisitor {
public:
    using Color = Piece::Color;

private:
    const Color _color;

    const Rook* _kingside_rook { nullptr };
    const Rook* _queenside_rook { nullptr };
    const King* _king { nullptr };

public:
    CastleVisitor() = delete;
    CastleVisitor(const Color color) :
            _color(color) {  }

    virtual ~CastleVisitor() = default;

    virtual void visit(const Bishop& piece) override;
    virtual void visit(const King& piece) override;
    virtual void visit(const Knight& piece) override;
    virtual void visit(const Pawn& piece) override;
    virtual void visit(const Queen& piece) override;
    virtual void visit(const Rook& piece) override;

    inline bool has_king() const { return _king != nullptr; }
    inline bool has_kingside_rook() const { return _kingside_rook != nullptr; }
    inline bool has_queenside_rook() const { return _queenside_rook != nullptr; }

    inline const King& get_king() const { return *_king; }
    inline const Rook& get_kingside_rook() const { return *_kingside_rook; }
    inline const Rook& get_queenside_rook() const { return *_queenside_rook; }
};

#endif
