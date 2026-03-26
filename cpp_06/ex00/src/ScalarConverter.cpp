#include "../includes/ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor is called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "ScalarConverter copy constructor is called!" << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other)
{
    std::cout << "ScalarConverter copy assignment operator is called!" << std::endl;
    (void)other;

    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor is called!" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    Type type;
    TypeDetector typeDetector;
    TypeConverter typeConverter;
    // char c;
    int i;
    float f;
    double d;

    type = typeDetector.detectType(literal);

    if (type == CHAR)
    {
        typeConverter.convertToChar(literal);
    }
    else if (type == INT)
    {
        typeConverter.convertToInt(literal);
    }
    else if (type == FLOAT)
    {
        typeConverter.convertToFloat(literal);
    }
    if (type == DOUBLE)
    {
        typeConverter.convertToDouble(literal);
    }
    else if (type == EMPTY)
        std::cout << "EMPTY" << std::endl;
}
