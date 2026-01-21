#include "FileManager.hpp"
#include <string>
#include <iostream>
#include <fstream>

FileManager::FileManager(std::string newFilename, std::string str1, std::string str2) 
    : filename(newFilename), s1(str1), s2(str2) {};

FileManager::~FileManager() {};

void FileManager::replace() {
    std::string line;
    std::fstream gFile(filename.c_str(), std::ios::in); // fstream - both reading and writing
    size_t str_idx;
    
    if (!gFile.is_open()) { // checks whether the file stream is successfully associated with an open file
        std::cout << "Check filename!" << std::endl;
        return ;
    }

    // .c_str() to convert std::string to const char*
    std::fstream copy((filename + ".replace").c_str(), std::ios::out);
    if (!copy.is_open()) {
        gFile.close();
        std::cout << "Check filename!" << std::endl;
        return ;
    }
    if (s1 == "" || s2 == "") {
        std::cout << "Empty string!" << std::endl;
        return ;
    }
    while (getline(gFile, line)) {
        str_idx = 0;
        while ((str_idx = line.find(s1, str_idx) )!= std::string::npos) {
            line.erase(str_idx, s1.length());
            line.insert(str_idx, s2);
            str_idx += s2.length();
        }
        copy << line << std::endl;
    }
    std::cout << "Copying finished" << std::endl;
    copy.close();
    gFile.close();
}
