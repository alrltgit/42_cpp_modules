#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T> void swap(T& val1, T& val2) {
    T temp = val1;
    val1= val2;
    val2 = temp;
}

template <typename T> T min(const T& val1, const T& val2) {
    return (val1 < val2) ? val1 : val2;
}

template <typename T> T max(const T& val1, const T& val2) {
    return (val1 > val2) ? val1 : val2;
}

#endif