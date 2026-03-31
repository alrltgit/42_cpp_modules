#include "Span.h"
#include <algorithm>

Span::Span() : N(0) {
    std::cout << "Span: default constructor is called." << std::endl;
}

Span::Span(unsigned int newN) : N(newN) {
    std::cout << "Span: parameterised constructor is called." << std::endl;
}

Span::Span(const Span& other) {
    std::cout << "Span: parameterised constructor is called." << std::endl;
    N = other.N;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Span: copy assignment operator is called." << std::endl;
    if (this != &other) {
        N = other.N;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Span: destructor is called." << std::endl;
}

const char* Span::SpanIsFull::what() const throw() {
    return "Can't add a value. The span is full.";
}

const char* Span::NotEnoughNumbers::what() const throw() {
    return "Span contains not enough numbers.";
}

const unsigned int Span::getN() const {
    return N;
}

void Span::addNumber(int num) {
    if (vect.size() == N) {
        throw SpanIsFull();
    }
    vect.push_back(num);
}
