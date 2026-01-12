#include <iostream>
#include <string>
#include <ctype.h>

class ToUpper {
    private:
        std::string default_message;
    
    public:
        ToUpper() {
            default_message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        };

    private:
        void convert_to_uppercase(int size, char** message) {
            int str_idx;
            int char_idx;
            std::string str;
            std::string temp_str;

            str_idx = 1;
            while (message[str_idx]) {
                str = message[str_idx];
                char_idx = 0;
                temp_str = "";
                while (str[char_idx]) {
                    temp_str += (char)toupper(str[char_idx]);
                    char_idx++;
                }
                std::cout << temp_str;
                str_idx++;
            }
            std::cout << std::endl;
        }

    public:
        void str_to_uppercase(int size, char** message) {
            if (size == 1)
                std::cout << default_message << std::endl;
            else
                convert_to_uppercase(size, message);
    }
};

int main(int argc, char **argv) {
    ToUpper test;
    test.str_to_uppercase(argc, argv);

    return 0;
}
