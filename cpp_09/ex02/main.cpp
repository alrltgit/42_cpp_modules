#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }

    try {
        PmergeMe ob = PmergeMe();
        ob.run(ac, av);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
