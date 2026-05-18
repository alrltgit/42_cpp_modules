#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        numsVector = other.numsVector;
        numsDeque = other.numsDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::storeNumsInContainers(int ac, char **av, T& container) {
    for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        int val;

        if (!(ss >> val) || val < 0 || !(ss >> std::ws).eof()) {
            throw std::runtime_error("Error: invalid number");
        }

        container.push_back(val);
    }
}

void PmergeMe::storeNums(int ac, char **av) {
    storeNumsInContainers(ac, av, numsVector);
    storeNumsInContainers(ac, av, numsDeque);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container) {
    if (container.size() <= 1)
        return ;

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        int a = container[i];
        int b = container[i + 1];

        if (a > b) {
            std::swap(a, b);
        }

        pairs.push_back(std::make_pair(a, b));
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

template <typename T>
void PmergeMe::printContainer(const T& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::run(int ac, char **av) {
    storeNums(ac, av);

    std::clock_t startVector = std::clock();
    mergeInsertSort(numsVector);
    std::clock_t endVector = std::clock();

    std::clock_t startDeque = std::clock();
    mergeInsertSort(numsDeque);
    std::clock_t endDeque = std::clock();

    double vectorTime = static_cast<double>(endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;
    double dequeTime = static_cast<double>(endDeque - startDeque) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printContainer(numsVector);

    std::cout << "Time to process a range of " << numsVector.size()
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << numsDeque.size()
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
