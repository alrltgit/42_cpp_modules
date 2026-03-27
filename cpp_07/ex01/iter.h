#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <vector>

template <typename T> void iter(std::vector<T, T> *list, const T listLength, T(*f)(T& val)) {
    for (size_t i = 0; i < listLength; ++i) {
        f(list[i]);
    }
}

#endif
