#include "FileManager.hpp"
#include <string>
#include <fstream>


int main() {
    // create and open a text file
    // std::ifstream givenFile("givenFile.txt");
    // std::ofstream copy("copy.txt");
    std::string givenFile = "givenFile";
    std::string str1 = "light";
    std::string str2 = "sun";
    FileManager manager(givenFile, str1, str2);
   
    // copy file
    manager.replace();

    
    return 0;
}
