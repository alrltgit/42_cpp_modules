#include "../includes/ScalarConverter.hpp"
#include "../includes/TypeDetector.hpp"
#include "../includes/TypeConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor is called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "ScalarConverter copy constructor is called!" << std::endl;
    static_cast<void>(other);
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other)
{
    std::cout << "ScalarConverter copy assignment operator is called!" << std::endl;
    static_cast<void>(other);

    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor is called!" << std::endl;
}

void ScalarConverter::convert(std::string& literal) {
    TypeDetector typeDetector;
    TypeConverter typeConverter;
    Type type = typeDetector.detectType(literal);

    if (literal == "+inff" || literal == "+inf"
        || literal == "-inff" || literal == "-inf"
        || literal == "nanf" || literal == "nan")
    {
        typeConverter.convertPseudoLiterals(literal);
        return ;
    }

    switch (type)
    {
        case CHAR:
            typeConverter.convertToChar(literal);
            break;
        case INT:
            typeConverter.convertToInt(literal);
            break;
        case FLOAT:
            typeConverter.convertToFloat(literal);
            break;
        case DOUBLE:
            typeConverter.convertToDouble(literal);
            break;
        case EMPTY:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}