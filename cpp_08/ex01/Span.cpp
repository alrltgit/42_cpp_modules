#include "Span.h"
#include <algorithm>
#include <limits>

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

unsigned int Span::getN() const {
    return N;
}

void Span::addNumber(int num) {
    if (vect.size() == N) {
        throw SpanIsFull();
    }
    vect.push_back(num);
}

int Span::shortestSpan() {
    if (vect.size() < 2) {
        throw NotEnoughNumbers();
    }

    int shortestSpan = std::numeric_limits<int>::max();

    sort(vect.begin(), vect.end());
    for (size_t i = 0; i < vect.size() - 1; ++i) {
        int tempSpan = vect[i] - vect[i + 1];
        if (tempSpan < 0)
            tempSpan *= -1;

        if (tempSpan < shortestSpan)
            shortestSpan = tempSpan;
    }

    return shortestSpan;
}

int Span::longestSpan() {
    if (vect.size() < 2) {
        throw NotEnoughNumbers();
    }

         
    std::vector<int>::iterator min_el = std::min_element(vect.begin(), vect.end());
    std::vector<int>::iterator max_el = std::max_element(vect.begin(), vect.end());

    return max_el - min_el;
}
