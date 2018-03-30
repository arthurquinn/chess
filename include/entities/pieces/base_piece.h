#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H


class BasePiece {
public:
    enum class PieceColor {
        BLACK,
        WHITE
    };

protected:
    PieceColor _color;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color);

    virtual ~BasePiece() = default;
};


#endif
