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

        // 1.open the file and copy its content to a new file
        // 3.replace every occurence of s1 with s2
        void replace();
};

#endif
