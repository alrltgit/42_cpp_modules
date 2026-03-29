#ifndef INC_42_CPP_MODULES_ARRAY_H
#define INC_42_CPP_MODULES_ARRAY_H

#include <exception>

template <typename T>
class Array {
private:
    unsigned int size;
    T *array;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator = (const Array& other);
    ~Array();

    class OutOfBoundException : public exception {
        virtual const char* what() const throw();
    };

    unsigned int& size() const;
    T& operator[](int idx);
};

#endif