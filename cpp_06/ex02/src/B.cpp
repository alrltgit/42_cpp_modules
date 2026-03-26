#include "../includes/B.hpp"

B::B()
{
    std::cout << "B: default constructor is called" << std::endl;
}

B::B(const B& other)
{
    (void)other;
    std::cout << "B: copy constructor is called" << std::endl;
}

B& B::operator = (const B& other)
{
    (void)other;
    std::cout << "B: copy assignment operator is called" << std::endl;
    return *this;
}

B::~B()
{
    std::cout << "B: destructor is called" << std::endl;
}
