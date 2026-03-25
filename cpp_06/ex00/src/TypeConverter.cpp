#include "../includes/TypeConverter.hpp"
#include <limits>
#include <cstdlib>

TypeConverter::TypeConverter() 
{
    std::cout << "TypeConverter default constructor is called" << std::endl;
}

TypeConverter::TypeConverter(const TypeConverter& other)
{
    (void)other;
    std::cout << "TypeConverter copy constructor is called" << std::endl;
}

TypeConverter& TypeConverter::operator = (const TypeConverter& other)
{
    (void)other;
    std::cout << "TypeConverter copy assignment operator is called" << std::endl;
    return *this;
}

TypeConverter::~TypeConverter()
{
    std::cout << "TypeConverter destructor is called" << std::endl;    
}

void TypeConverter::convertToChar(std::string& literal)
{
    char c;
    int i;
    float f;
    double d;

    // convert to char
    c = literal[0];
    if (c)
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    // convert to int
    i = std::atoi(literal.c_str());
    if (i)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // convert to float
    // check for edge cases
    if (literal == "+inff" || literal == "innf")
        f = +std::numeric_limits<float>::infinity();
    else if (literal == "-inff")
        f = -std::numeric_limits<float>::infinity();
    else if (literal == "nanf")
        f = -std::numeric_limits<float>::quiet_NaN();
    else
        f = std::atof(literal.c_str());
    if (f)
        std::cout << "float: " << f << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    // convert to double
    // check for edge cases
    if (literal == "+inff" || literal == "innf")
        d = +std::numeric_limits<double>::infinity();
    else if (literal == "-inff")
        d = -std::numeric_limits<double>::infinity();
    else if (literal == "nanf")
        d = -std::numeric_limits<double>::quiet_NaN();
    else
        d = std::atof(literal.c_str());
    if (d)
        std::cout << "double " << d << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}
