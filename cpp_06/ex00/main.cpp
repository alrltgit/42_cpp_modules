#include "includes/ScalarConverter.hpp"
#include "includes/TypeDetector.hpp"

int main()
{
    ScalarConverter::convert("a");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("42.42f");
    ScalarConverter::convert("-inff"); // positive infinity (float)
    ScalarConverter::convert("+inff"); // negative infinity (float)
    ScalarConverter::convert("nanf"); // not a number (float)
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("-inf"); // positive infinity (float)
    ScalarConverter::convert("+inf"); // negative infinity (float)
    ScalarConverter::convert("nan");


    return 0;
}
