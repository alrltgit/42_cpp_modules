#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T *list, size_t listLength, void(*f)(T& val)) {
    for (size_t i = 0; i < listLength; ++i) {
        f(list[i]);
    }
}

template <typename T>
void iter(const T* list, size_t listLength, void(*f)(const T& val)) {
    for (size_t i = 0; i < listLength; ++i) {
        f(list[i]);
    }
}

#endif
