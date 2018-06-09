#ifndef __STL_HELPER_H
#define __STL_HELPER_H

#include <vector>

class STL_Helper {
private:

public:
    STL_Helper() = delete;
    ~STL_Helper() = delete;

    template<typename T>
    inline static void append_vectors(std::vector<T>& v1, const std::vector<T>& v2) {
        v1.insert(v1.end(), v2.cbegin(), v2.cend());
    }
};

#endif
