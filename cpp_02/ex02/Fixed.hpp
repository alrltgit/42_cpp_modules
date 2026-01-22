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

        Fixed operator++(int); // postfix operator implementation // return Fixed object by value, i.g. the copy of Fixed object
        Fixed operator--(int); // postfix operator implementation
        Fixed& operator++(); // prefix operator implementation
        Fixed& operator--(); // prefix operator implementation

        static Fixed& min(Fixed& obj1, Fixed& obj2); // static func can be called without creating an object, does not have access to this pointer
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
        static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
    };

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
