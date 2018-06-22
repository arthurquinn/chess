#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "interfaces/controller.h"
#include "interfaces/piece.h"

#include <memory>
#include <vector>
#include <string>
#include <experimental/optional>

class Keyboard : public Controller {
private:
    template<typename T>
    using opt = std::experimental::optional<T>;

    using TokenList = std::vector<std::string>;
    using Location = Piece::Location;

    inline unsigned char file2ordinal(const unsigned char file) const {
        return tolower(file) - 97;
    }

    inline unsigned char rank2ordinal(const unsigned char rank) const {
        return rank - 49;
    }

    TokenList split(const std::string& str, const char delim) const;

    opt<Location> parse_loc(const std::string& str) const;
    std::unique_ptr<Command> parse_move_piece(const TokenList& tokens) const;
    std::unique_ptr<Command> parse_possible_moves(const TokenList& tokens) const;


public:
    Keyboard() = default;
    virtual ~Keyboard() = default;

    virtual std::unique_ptr<Command> getCommand() const override;
};

#endif
