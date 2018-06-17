#ifndef __STL_HELPER_H
#define __STL_HELPER_H

#include <vector>
#include <algorithm>

class STL_Helper {
private:

public:
    STL_Helper() = delete;
    ~STL_Helper() = delete;

    template<typename T>
    inline static void append_vectors(std::vector<T>& v1, const std::vector<T>& v2) {
        v1.insert(v1.end(), v2.cbegin(), v2.cend());
    }

    template<typename T, typename Predicate>
    inline static void filter_vector(std::vector<T>& v, const Predicate& predicate) {
        v.erase(std::remove_if(v.begin(), v.end(), predicate), v.end());
    }

    template<typename T>
    inline static bool vector_contains(const std::vector<T>& v, const T& value) {
        return std::find(v.cbegin(), v.cend(), value) != v.cend();
    }
};

#endif
