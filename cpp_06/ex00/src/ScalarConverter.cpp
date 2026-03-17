#include "ScalarConverter.hpp"
#include <sstream>

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
    char c;
    int i;
    float f;
    double d;

    type = typeDetector.detectType(literal);

}
