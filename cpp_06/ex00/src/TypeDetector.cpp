#include "../includes/TypeDetector.hpp"

TypeDetector::TypeDetector()
{
    std::cout << "TypeDetector constructor is called" << std::endl;
}

TypeDetector::TypeDetector(const TypeDetector& other)
{
    std::cout << "TypeDetector copy constructor is called" << std::endl;
    (void)other;
}

TypeDetector& TypeDetector::operator = (const TypeDetector& other)
{
    std::cout << "TypeDetector copy assognment operator is called" << std::endl;
    (void)other;
    return *this;
}

TypeDetector::~TypeDetector()
{
    std::cout << "TypeDetector destructor is called" << std::endl;
}

bool TypeDetector::isInt(const std::string& l)
{
    for (size_t i = 0; i < l.length(); ++i)
    {
        if (i == 0)
        {
            if (l[0] == '-' || l[0] == '+')
                continue;
        }
        if (!isdigit(l[i]))
            return false;
    }
    return true;
}

bool TypeDetector::isFloat(const std::string& l)
{
    int hasDot = 0;

    if (l == "-inff" || l == "+inff" || l == "nanf")
        return true;

    if (l[l.length() - 1] != 'f')
        return false;

    for (size_t i = 0; i < l.length(); ++i)
    {
        if (l[0] == '+' || l[0] == '-')
            continue;

        if (l[i] == 'f')
            continue;

        if (l[i] == '.')
        {
            hasDot++;
            continue;
        }
        
        if (!isdigit(l[i]) || hasDot > 1)
            return false;
    }

    if (hasDot == 0)
        return false;
    
    return true;
}

bool TypeDetector::isDouble(const std::string& l)
{
    int hasDot = 0;

    if (l == "-inf" || l == "+inf" || l == "nan")
        return true;
    
    for (size_t i = 0; i < l.length(); ++i)
    {
        if (l[0] == '+' || l[0] == '-')
            continue;
        
        if (l[i] == '.')
        {
            hasDot++;
            continue;
        }
        
        if (!isdigit(l[i]) || hasDot > 1)
            return false;
    }

    if (hasDot == 0)
        return false;
    
    return true;
}

Type TypeDetector::detectType(const std::string& l)
{
    // check if the literal is char
    if (l.length() == 1 && !isdigit(l[0]))
        return CHAR;
    
    // check if the literal is int
    if (isInt(l))
        return INT;
    
    // check if the literal is float
    if (isFloat(l))
        return FLOAT;

    // check if the literal is double
    if (isDouble(l))
        return DOUBLE;
    
    return EMPTY;
}
