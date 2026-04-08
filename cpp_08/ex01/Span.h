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

        template <typename T>
        void addNumbers(T& nums) {
            size_t distance = std::distance(nums.begin(), nums.end());

            if (vect.size() + distance > N)
                throw std::runtime_error("Nums size exceeds span size.");

            vect.insert(vect.end(), nums.begin(), nums.end()); // vect.interst(gdzie wstawić, początek zakresu, koniec zakresu)
        }

        void addNumber(int num);
        unsigned int getN() const;    
        int shortestSpan();
        int longestSpan();
};

#endif
