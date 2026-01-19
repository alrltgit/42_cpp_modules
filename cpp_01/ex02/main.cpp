#include <iostream>

int main () {
    std::string var = "HI THIS IS BRAIN";
    
    std::string* stringPTR = &var;
    std::string& stringREF = var;

    std::cout << "The memory address of string variable is " << &var << std::endl;
    std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of string variable is " << var << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is " << stringREF << std::endl;

    return 0;
}
