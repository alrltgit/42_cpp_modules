#include "FileManager.hpp"
#include <string>
#include <iostream>
#include <fstream>

FileManager::FileManager(std::string newFilename, std::string str1, std::string str2) 
    : filename(newFilename), s1(str1), s2(str2) {};

FileManager::~FileManager() {};

void FileManager::replace() {
    std::string line;
    std::ifstream gFile(filename);
    size_t str_idx;
    
    if (!gFile) {
        std::cout << "Check filename!" << std::endl;
        exit(1);
    }
    else {
        std::ofstream copy(filename + ".replace");
        while (getline(gFile, line)) {
            str_idx = 0;
            while ((str_idx = line.find(s1, str_idx) )!= std::string::npos) {
                line.erase(str_idx, s1.length());
                line.insert(str_idx, s2);
            }
            copy << line << std::endl;
        }
        std::cout << "Copying finished" << std::endl;
        copy.close();
    }
    gFile.close();
}
