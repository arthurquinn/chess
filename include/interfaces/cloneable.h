#ifndef __CLONEABLE_H
#define __CLONEABLE_H

#include <memory>

template<typename T>
class Cloneable {
private:

public:
    Cloneable() = default;
    virtual ~Cloneable() = default;

    virtual T clone() const = 0;
};

#endif
