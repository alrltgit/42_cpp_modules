#ifndef TYPE_DETECTOR_HPP
#define TYPE_DETECTOR_HPP

#include <iostream>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    EMPTY
};

class TypeDetector
{
    public:
        TypeDetector();
        TypeDetector(const TypeDetector& other);
        TypeDetector& operator = (const TypeDetector& other);
        ~TypeDetector();

        Type detectType(const std::string& l);
        bool isInt(const std::string& l);
        bool isFloat(const std::string& l);
        bool isDouble(const std::string& l);
};

#endif
