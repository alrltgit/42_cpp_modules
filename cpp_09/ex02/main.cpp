#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i) {
        std::cout << av[i] << ' ';
    }
    std::cout << std::endl;

    try {
        PmergeMe ob = PmergeMe();
        ob.sort(ac, av);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
