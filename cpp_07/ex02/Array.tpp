#include <iostream>

template <typename T>
Array<T>::Array() : arrSize(0), array(new T[0]) {
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arrSize(n), array(new T[arrSize]) {
    std::cout << "Array parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) {
    std::cout << "Array copy constructor called" << std::endl;
    arrSize  = other.arrSize;
    delete [] array;
    array = new T[arrSize];

    for (size_t i = 0; i < arrSize; ++i) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator = (const Array& other) {
    std::cout << "Array copy assignment operator called" << std::endl;

    if (this != &other) {
        arrSize  = other.arrSize;
        delete [] array;
        array = new T[arrSize];

        for (size_t i = 0; i < arrSize; ++i) {
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
const char* Array<T>::OutOfBoundException::what() const throw() {
    return "Index is out of bound.";
}

template <typename T>
T* Array<T>::getArray() const {
    return array;
}

template <typename T>
unsigned int Array<T>::size() const {
    return arrSize;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
    if (idx >= arrSize) {
        throw Array<T>::OutOfBoundException();
    }
    return array[idx];
}
