#include <iostream>

int main () {
    std::string var = "HI THIS IS BRAIN";
    
    // pointer to the string (a variable that stores an address):
    // - can be null
    // - can be reassigned
    std::string* stringPTR = &var;

    // reference to the string (another name for an existing object)
    // can't be null
    // can't be reassigned
    std::string& stringREF = var; // stringRef is another name for var

    std::cout << "The memory address of string variable is " << &var << std::endl;
    std::cout << "The memory address held by stringPTR is " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of string variable is " << var << std::endl;
    std::cout << "The value pointed to by stringPTR is " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is " << stringREF << std::endl;

    return 0;
}
