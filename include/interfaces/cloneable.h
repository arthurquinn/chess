#ifndef __CLONEABLE_H
#define __CLONEABLE_H

#include <memory>

template<class T>
class Cloneable {
public:
    Cloneable() = default;
    virtual ~Cloneable() = default;

    virtual std::unique_ptr<T> clone() const = 0;
};

#endif
