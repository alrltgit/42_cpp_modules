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

    // std::cout << "container: " ;
    // for (size_t i = 0; i < container.size(); ++i) {
    //     std::cout << container[i] << ' ';
    // }
    std::cout << std::endl;
}

void PmergeMe::storeNums(int ac, char **av) {
    storeNumsInContainers(ac, av, numsVector);
    storeNumsInContainers(ac, av, numsDeque);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container) {
    // std::cout << "container.size(): " << container.size() << std::endl;
    if (container.size() <= 1)
        return ;

    // split into pairs and sort the pairs
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        int a = container[i];
        int b = container[i + 1];

        if (a > b) {
            std::swap(a, b);
        }

        pairs.push_back(std::make_pair(a, b));
    
        // for (size_t i = 0; i < pairs.size(); i++) {
        //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
        // }
    }

    int lastDigit = -1;
    bool oddPairs = false;

    if (container.size() % 2 != 0) {
        lastDigit = container.back();
        oddPairs = true;
    }
    
    std::vector<int> largerNums;
    std::vector<int> smallerNums;

    for (size_t i = 0; i < pairs.size(); ++i) {
        largerNums.push_back(pairs[i].second);
        smallerNums.push_back(pairs[i].first);
    }

    mergeInsertSort(largerNums);

    for (size_t i = 0; i < smallerNums.size(); ++i) {
        int val = smallerNums[i];

        std::vector<int>::iterator pos = std::lower_bound(largerNums.begin(), largerNums.end(), val);

        largerNums.insert(pos, val);
    }

    if (oddPairs) {
        std::vector<int>::iterator pos = std::lower_bound(largerNums.begin(), largerNums.end(), lastDigit);
        largerNums.insert(pos, lastDigit);
    }

    container.assign(largerNums.begin(), largerNums.end());
}

void PmergeMe::run(int ac, char **av) {
    storeNums(ac, av);
    mergeInsertSort(numsVector);
    mergeInsertSort(numsDeque);

    std::cout << "numsVector: " ;
    for (size_t i = 0; i < numsVector.size(); ++i) {
        std::cout << numsVector[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "numsDeque: " ;
    for (size_t i = 0; i < numsDeque.size(); ++i) {
        std::cout << numsDeque[i] << ' ';
    }
    std::cout << std::endl;
}
