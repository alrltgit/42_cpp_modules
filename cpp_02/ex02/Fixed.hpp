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

        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
    };

std::ostream & operator<<(std::ostream& out, const Fixed& obj);

#endif
