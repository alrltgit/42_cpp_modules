#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl_obj;

    if (ac != 2) {
        std::cout << "Wrong number of arguments" << std::endl;
        exit(1);
    }

    harl_obj.complain(av[1]);
    return 0;
}

