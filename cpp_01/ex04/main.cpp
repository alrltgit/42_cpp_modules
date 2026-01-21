#include "FileManager.hpp"
#include <string>
#include <fstream>


int main(int ac, char** av) {
    if (ac != 4) {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string givenFile = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    FileManager manager(givenFile, str1, str2);
   
    // copy file
    manager.replace();

    
    return 0;
}
