#include "includes/ScalarConverter.hpp"
#include "includes/TypeDetector.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string literal = av[0];

    ScalarConverter::convert(literal);

    return 0;
}
