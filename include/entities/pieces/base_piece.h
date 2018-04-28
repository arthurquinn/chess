#ifndef __BASE_PIECE_H
#define __BASE_PIECE_H

#include <utility>
#include <vector>
#include <memory>

#include "interfaces/printable.h"

class Board;

class BasePiece : public Printable {
public:

    // Location::first is rank
    // Location::second is file
    using Location = std::pair<int, int>;
    enum class PieceColor {
        INVALID,
        WHITE,
        BLACK
    };

protected:
    const PieceColor _color;
    Location _location;

    char color_char() const;
    bool opposing_colors(const std::unique_ptr<BasePiece>& other) const;

    void check_path(const Board& board, std::vector<Location>& locs, int r, int f, const int dr, const int df) const;
    void check_diagonals(const Board& board, std::vector<Location>& locs) const;
    void check_across(const Board& board, std::vector<Location>& locs) const;

public:
    BasePiece() = delete;
    BasePiece(const PieceColor color, const int r, const int f);

    virtual ~BasePiece() = default;

    inline PieceColor color() const { return _color; }

    virtual void move(const int r, const int f);
    
    virtual const std::vector<Location> possible_moves(const Board& board) const = 0;

    virtual void print(std::ostream& os) const = 0;
};


#endif
