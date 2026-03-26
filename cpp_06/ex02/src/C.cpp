#include "../includes/C.hpp"

C::C()
{
    std::cout << "C: default constructor is called" << std::endl;
}

C::C(const C& other)
{
    (void)other;
    std::cout << "C: copy constructor is called" << std::endl;
}

C& C::operator = (const C& other)
{
    (void)other;
    std::cout << "C: copy assignment operator is called" << std::endl;
    return *this;
}

C::~C()
{
    std::cout << "C: destructor is called" << std::endl;
}
