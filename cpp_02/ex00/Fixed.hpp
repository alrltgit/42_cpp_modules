#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int fixedPointNb;
        static const int val = 8;

    public:
        Fixed();
        Fixed(const Fixed& other); // copy constructor
        Fixed& operator = (const Fixed& other); // copy assignment operator
        ~Fixed();

        int getRawBits(void) const; // that returns the raw value of the fixed-point value.
        void setRawBits(int const raw); //  sets the raw value of the fixed-point number
};

#endif
