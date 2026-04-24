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

void RPN::readInput(char *avg) {
    std::string av(avg);

    for (size_t i = 0; i < av.length(); ++i) {

        switch (av[i]) {

            case '+':
            case '-':
            case '*':
            case '/':
                if (operands.size() < 2) {
                    std::cerr << "Error" << std::endl;
                    return ;
                }
                conductOperation(av[i]);
                break ;
            
            case ' ':
                break ;
            
            default:
                if (isdigit(av[i])) {
                    int token = av[i] - '0';
                    operands.push(token);
                } else {
                    std::cerr << "Error" << std::endl;
                    return ;
                }
            }

    }
    
    if (operands.size() != 1) {
        std::cerr << "Error" << std::endl;
        return ;
    }

    std::cout << operands.top() << std::endl;
}

void RPN::conductOperation(char av) {
    int operand = operands.top();
    operands.pop();
    int res = -1;

    if (av == '+') {
        res = operand + operands.top();
    } else if (av == '-') {
        res = operands.top() - operand;
    } else if (av == '*') {
        res = operand * operands.top();
    } else if (av == '/') {
        res = operands.top() / operand;
    }

    operands.pop();
    operands.push(res);
}
