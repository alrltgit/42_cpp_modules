#ifndef SPAN_H
#define SPAN_H

#include <exception>
#include <iostream>
#include <vector>

class Span {
    private:
        unsigned int N;
        std::vector<int> vect;
    
    public:
        Span();
        Span(unsigned int newN);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        class SpanIsFull : public std::exception {
            virtual const char* what() const throw();
        };

        class NotEnoughNumbers : public std::exception {
            virtual const char* what() const throw();
        };

        const unsigned int getN() const;
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
};

#endif
