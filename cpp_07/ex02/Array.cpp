#include "Array.h"

template <typename T>
Array<T>::Array() : arrSize(0), array(NULL) {
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arrSize(n) {
    std::cout << "Array parameterized constructor called" << std::endl;

    array = new T[arrSize];
}

template <typename T>
Array<T>::Array(const Array& other) {
    std::cout << "Array copy constructor called" << std::endl;
    arrSize  = other.arrSize;
    array = new T[arrSize];

    for (size_t i = 0; i < array.length(); ++i) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array& Array<T>::operator = (const Array& other) {
    std::cout << "Array copy assignment operator called" << std::endl;

    if (this != &other) {
        size  = other.size;
        array = new T[size];

        for (size_t i = 0; i < array.length(); ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    delete [] array;
}

template <typename T>
unsigned int& Array<T>::size() const {
    return arrSize;
}

template <typename T>
T& Array<T>::operator[](int idx) {
    return array[idx];
}
