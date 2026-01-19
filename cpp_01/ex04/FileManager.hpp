#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <iostream>
#include <string>

class FileManager {
    private:
        std::string filename;
        std::string s1;
        std::string s2;

    public:
        FileManager(std::string filename, std::string s1, std::string s2);
        ~FileManager();

        void replace();
};

#endif
