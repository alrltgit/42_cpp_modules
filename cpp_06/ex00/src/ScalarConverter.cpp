#include "../includes/ScalarConverter.hpp"
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

    if (type == CHAR)
    {
        c = literal[0];
        if (c)
            std::cout << "Convertint to char: " << c << std::endl;
        else
            std::cout << "The converted to char literal is not displayable" << std::endl;
    }
    else if (type == INT)
    {
        i = std::atoi(literal.c_str());
        std::cout << "Converting to int: " << i << std::endl;
    }
    else if (type == FLOAT)
    {
        if (literal == "+inff" || literal == "innf")
            f = +std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else if (literal == "nanf")
            f = -std::numeric_limits<float>::quiet_NaN();
        else
            f = std::atof(literal.c_str());
        std::cout << "Converting to float: " << f << std::endl;
    }
    if (type == DOUBLE)
    {
        if (literal == "+inff" || literal == "innf")
            d = +std::numeric_limits<double>::infinity();
        else if (literal == "-inff")
            d = -std::numeric_limits<double>::infinity();
        else if (literal == "nanf")
            d = -std::numeric_limits<double>::quiet_NaN();
        else
            d = std::atof(literal.c_str());
        std::cout << "Converting to double: " << d << std::endl;
    }
    else if (type == EMPTY)
        std::cout << "EMPTY" << std::endl;
}
