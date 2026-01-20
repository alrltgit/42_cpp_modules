#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int fixedPointNb;
        static const int fractBits = 8;

    public:
        Fixed();

        Fixed(const int newFixedPointNb);
        Fixed(const float newFixedPointNb);

        Fixed(const Fixed& other); // copy constructor
        Fixed& operator = (const Fixed& other); // copy assignment operator
        ~Fixed();

        int getRawBits(void) const; // that returns the raw value of the fixed-point value.
        void setRawBits(int const raw); //  sets the raw value of the fixed-point number
        float toFloat(void) const;
        int toInt(void) const;
    };

std::ostream & operator<<(std::ostream& out, const Fixed& obj);

#endif
