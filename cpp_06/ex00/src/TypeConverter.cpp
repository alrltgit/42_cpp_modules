#include "../includes/TypeConverter.hpp"
#include <limits>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <cfloat>

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

void TypeConverter::convertPseudoLiterals(std::string& literal)
{
    if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "nanf" || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void TypeConverter::convertToChar(std::string& literal)
{
    char c = static_cast<char>(literal[0]);

    if (!isprint(c))
    {
        std::cout << "char: non dislayable" << std::endl;
        return ;
    }
    else
    {
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
}

void TypeConverter::convertToInt(std::string& literal)
{
    long int val;

    val = std::atol(literal.c_str());

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;

    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    // type casting using cast operator - static_cast; static_cast performs compile time type conversions
    std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

#include <typeinfo>

void TypeConverter::convertToFloat(std::string& literal) 
{
    std::stringstream ss;
    float val;

    ss << literal;
    ss >> val;

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;

    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    
    if (val < FLT_MIN || val > FLT_MAX) 
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

// check the range when converting double to a smaller or different type: int, float, char

void TypeConverter::convertToDouble(std::string& literal)
{
    std::stringstream ss;
    double val;

    ss << literal;
    ss >> val;

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;

    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    
    if (val < FLT_MIN || val > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << std::endl;

    if (val < DBL_MIN || val > DBL_MAX)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}
