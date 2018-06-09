#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>

class BasePiece {
public:
    using Location = std::pair<int, int>;

    enum class Color {
        INVALID,
        BLACK,
        WHITE
    };

private:
    Color _color;
    Location _location;

public:
    BasePiece() = default;
    virtual ~BasePiece() = default;

    
};

#endif
