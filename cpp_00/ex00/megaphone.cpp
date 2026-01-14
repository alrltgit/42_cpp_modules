#include <iostream>
#include <cctype>

int main(int argc, char *argv[]) {
    std::string str;
    std::string temp_str;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++) {
            str = argv[i];
            temp_str = "";
            for (int char_idx = 0; char_idx < str.length(); char_idx++)
                temp_str += (char)toupper(str[char_idx]);
            std::cout << temp_str;
        }
        std::cout << std::endl;
    }
    return 0;
}
