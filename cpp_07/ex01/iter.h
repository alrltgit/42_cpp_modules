#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename F>
void iter(T *list, const size_t listLength, F f) {
    for (size_t i = 0; i < listLength; ++i) {
        f(list[i]);
    }
}

template <typename T, typename F>
void iter(const T *list, const size_t listLength, F f) {
    for (size_t i = 0; i < listLength; ++i) {
        f(list[i]);
    }
}

#endif
