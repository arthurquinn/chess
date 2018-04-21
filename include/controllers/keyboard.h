#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "interfaces/controller.h"
#include "entities/pieces/base_piece.h"

#include <experimental/optional>
#include <vector>
#include <string>

class Keyboard : public Controller {
private:
    using TokenList = std::vector<std::string>;

    inline unsigned char file2ordinal(const unsigned char file) const {
        return tolower(file) - 97;
    }

    inline unsigned char rank2ordinal(const unsigned char rank) const {
        return rank - 49;
    }

    TokenList split(const std::string& str, const char delim) const;

    std::experimental::optional<BasePiece::Location> parse_loc(const std::string& strloc) const;

    std::unique_ptr<Action> parse_move(const TokenList& tokens) const;

    std::unique_ptr<Action> parse_possible(const TokenList& tokens) const;

public:
    Keyboard() = default;
    virtual ~Keyboard() = default;

    std::unique_ptr<Action> get() override;
};


#endif
