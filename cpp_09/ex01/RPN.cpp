#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        operands = other.operands;
    
    return *this;
}

RPN::~RPN() {}

bool RPN::readInput(char *avg) {
    std::string av(avg);

    for (size_t i = 0; i < av.length(); ++i) {

        switch (av[i]) {

            case '+':
            case '-':
            case '*':
            case '/':
                if (operands.size() < 2) {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
                if (!conductOperation(av[i]))
                    return false;
                break ;
            
            case ' ':
                break ;
            
            default:
                if (isdigit(av[i])) {
                    int token = av[i] - '0';
                    operands.push(token);
                } else {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
            }

    }
    
    if (operands.size() != 1) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    std::cout << operands.top() << std::endl;
    return true;
}

bool RPN::conductOperation(char op) {
    int right = operands.top(); operands.pop();
    int left  = operands.top(); operands.pop();
 
    if (op == '/' && right == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        return false;
    }
 
    int res;
    if      (op == '+') 
        res = left + right;
    else if (op == '-') 
        res = left - right;
    else if (op == '*') 
        res = left * right;
    else                
        res = left / right;
 
    operands.push(res);
    return true;
}
