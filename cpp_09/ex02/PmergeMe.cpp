#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;    
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::storeNumsInContainers(int ac, char **av, T& container) {
    for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        int val;
        ss >> val;

        if (ss.fail() || val < 0) {
            throw std::runtime_error("Error: invalid number");
        }
        
        container.push_back(val);
    }

    std::cout << "container: " ;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::sort(int ac, char **av) {
    storeNumsInContainers(ac, av, numsVector);
    storeNumsInContainers(ac, av, numsDeque);
}
