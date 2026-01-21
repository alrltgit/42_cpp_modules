#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointNb(0) {
    std::cout <<  "Default constructor called" << std::endl;
};

Fixed::Fixed(const int newFixedPointNb) 
    : fixedPointNb(newFixedPointNb << fractBits) {
        std::cout << "Int constructor called" << std::endl;
    };

Fixed::Fixed(const float newFixedPointNb)
    : fixedPointNb(roundf(newFixedPointNb * (1 << fractBits))) {
        std::cout << "Float constructor called" << std::endl;
    };

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator = (const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPointNb = other.getRawBits();
    
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNb;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    fixedPointNb = raw;
}

float Fixed::toFloat(void) const {
    return (float)fixedPointNb / (1 << fractBits);
};

int Fixed::toInt(void) const {
    return fixedPointNb >> fractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return out;
};

bool Fixed::operator>(const Fixed& other) const {
    return this->toFloat() > other.toFloat();
};

bool Fixed::operator<(const Fixed& other) const {
    return this->toFloat() < other.toFloat();
};

bool Fixed::operator>=(const Fixed& other) const {
    return this->toFloat() >= other.toFloat();
};

bool Fixed::operator<=(const Fixed& other) const {
    return this->toFloat() <= other.toFloat();
};

bool Fixed::operator==(const Fixed& other) const {
    return this->toFloat() == other.toFloat();
};

bool Fixed::operator!=(const Fixed& other) const {
    return this->toFloat() != other.toFloat();
};

Fixed Fixed::operator+(const Fixed& other) const {
    return this->toFloat() + other.toFloat();
};

Fixed Fixed::operator-(const Fixed& other) const {
    return this->toFloat() - other.toFloat();
};

Fixed Fixed::operator*(const Fixed& other) const {
    return this->toFloat() * other.toFloat();
}  

Fixed Fixed::operator/(const Fixed& other) const {
    return this->toFloat() / other.toFloat();
}


