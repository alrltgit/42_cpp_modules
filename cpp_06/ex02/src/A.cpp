#include "../includes/A.hpp"

A::A()
{
    std::cout << "A: default constructor is called" << std::endl;
}

A::A(const A& other)
{
    (void)other;
    std::cout << "A: copy constructor is called" << std::endl;
}

A& A::operator = (const A& other)
{
    (void)other;
    std::cout << "A: copy assignment operator is called" << std::endl;
    return *this;
}

A::~A()
{
    std::cout << "A: destructor is called" << std::endl;
}
