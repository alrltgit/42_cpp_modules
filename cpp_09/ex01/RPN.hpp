#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
    private:
        std::stack<int> operands;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        bool readInput(char *av);
        bool conductOperation(char av);
};

#endif
