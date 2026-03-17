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
    private:
        Type detectedType;

    public:
        TypeDetector();
        TypeDetector(const TypeDetector& other);
        TypeDetector& operator = (const TypeDetector& other);
        ~TypeDetector();

        Type detectType(const std::string& l);
        bool is_int(const std::string& l);
        bool is_float(const std::string& l);
        bool is_double(const std::string& l);
};

#endif
