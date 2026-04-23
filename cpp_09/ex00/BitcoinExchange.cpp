#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdlib.h>
#include <limits.h>
#include <stdexcept>
#include <cctype>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool dateIsValid(std::string line, size_t pos) {
    // does '|' is present on the line
    if (pos == std::string::npos)
        return false;

    // is format Year-Month-Day
    for (size_t i = 0; i < line.length(); ++i) {
        if (((i < 4) ||  (i > 4 && i < 7) || (i > 7 && i < 10)) && !isdigit(line[i]))
            return false;

        if ((i == 4 || i == 7) && line[i] != '-')
            return false;
    }

    // month is valid
    int month;
    std::stringstream ss(line.substr(5, 7));
    ss >> month;

    if (month < 1 || month > 12)
        return false;
    
    // day is valid
    int day;
    std::stringstream sr(line.substr(8, 10));
    sr >> day;

    int year;
    std::stringstream st(line.substr(0, 4));
    st >> year;

    if (month == 2) {
        int maxDays = isLeapYear(year) ? 29 : 28;
        return day <= maxDays;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
            return day <= 30;
    else
        return day <= 31;

    return true;
}

bool valueIsValid(double val) {
    // is negative number
    if (val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    // is value too large
    if (val > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

float getRate(std::string date) {
    char fullPath[PATH_MAX];

    if (!realpath("data.csv", fullPath))
        throw std::runtime_error("Path to the file is not found");

    std::ifstream data(fullPath);
    if (!data.is_open())
        throw std::runtime_error("Error opening the file");

    std::string rateStr;
    std::string line;
    while (getline(data, line)) {
        // std::cout << "line: " << line << std::endl;
        std::string temp = line.substr(0, line.find(','));
        temp.erase(0, temp.find_first_not_of(" \t"));
        temp.erase(temp.find_last_not_of(" \t") + 1);

        if (temp == date) {
            rateStr = line.substr(line.find(',') + 1);
            break ;
        }
    }

    char* end;
    float rate = std::strtof(rateStr.c_str(), &end);

    if (*end != '\0')
        return -1;

    return rate;
}

void BitcoinExchange::parseLine(std::string line, char delimiter) {
    size_t pos = line.find(delimiter);

    // date is valid
    if (!dateIsValid(line, pos)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    
    std::string date = line.substr(0, pos);
    std::string valStr = line.substr(pos+1);

    valStr.erase(0, valStr.find_first_not_of(" \t"));
    valStr.erase(valStr.find_last_not_of(" \t") + 1);

    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);

    if (valStr.empty()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    // convert to float
    char *end;
    double val = std::strtod(valStr.c_str(), &end);

    if (*end != '\0') {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    if (!valueIsValid(val))
        return ;

    float rate = getRate(date);
    std::cout << "rate: " << rate << std::endl;

    btcData[date] = val * rate;
}

void BitcoinExchange::storeDataInMap(char **argv) {
    char fullPath[PATH_MAX];

    if (!realpath(argv[1], fullPath))
        throw std::runtime_error("Path to the file is not found");

    std::ifstream data(fullPath);
    if (!data.is_open())
        throw std::runtime_error("Error opening the file");

    std::string line;
    while (getline(data, line))
        parseLine(line, '|');

    std::map<std::string, float>::iterator it;
    for (it = btcData.begin(); it != btcData.end(); ++it) {
        std::cout << " btcData[" << it->first << "] = " << it->second << std::endl;
    }

    data.close();
}
