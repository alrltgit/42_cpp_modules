#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNb(0) {
    std::cout <<  "Default constructor called" << std::endl;
};

// A copy constructor is a special type of constructor 
// used to create a new object using an existing object 
// of the same class.
// Copy Constructor
// Purpose
// Creates a new object as a copy of an existing one.
// When it’s called
// When a new object is initialized from another object
// When an object is passed by value
// When an object is returned by value (ignoring optimizations)
// When an exception is thrown or caught by value

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
// Purpose
// Copies data into an already existing object.
// When it’s called
// When an object is assigned after it has been created

// Works on an already constructed object
// Must handle self-assignment
// Often needs to release existing resources first
// Returns *this

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
