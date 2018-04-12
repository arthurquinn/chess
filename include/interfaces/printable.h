#ifndef __PRINTABLE_H
#define __PRINTABLE_H

#include <sstream>

class Printable {
private:

public:
    Printable() = default;
    virtual ~Printable() = default;

    virtual void print(std::ostream& os) const = 0;
};


#endif
