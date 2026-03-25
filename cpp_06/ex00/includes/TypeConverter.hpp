#ifndef TYPE_CONVERTER
#define TYPE_CONVERTER

#include <iostream>

class TypeConverter
{
    public:
        TypeConverter();
        TypeConverter(const TypeConverter& other);
        TypeConverter& operator = (const TypeConverter& other);
        ~TypeConverter();

        void convertToChar(std::string& literal);
        void convertToInt(std::string& literal);
        void convertToFloat(std::string& literal);
        void convertToDouble(std::string& literal);
};

#endif
