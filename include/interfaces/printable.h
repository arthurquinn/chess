#ifndef __PRINTABLE_H
#define __PRINTABLE_H

#include <ostream>

class Printable {
public:
    Printable() = default;
    virtual ~Printable() = default;

    virtual void print(std::ostream& os) const = 0;
};

#endif
