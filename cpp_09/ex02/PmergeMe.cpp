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

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t n) const {
    std::vector<size_t> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (true) {
        size_t next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        if (next >= n) {
            seq.push_back(n);
            break;
        }
        seq.push_back(next);
    }
    return seq;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t n) const {
    if (n == 0)
        return std::vector<size_t>();
 
    std::vector<size_t> jac = jacobsthalSequence(n);
    std::vector<size_t> order;
    std::vector<bool>   inserted(n, false);
 
    for (size_t k = 1; k < jac.size(); ++k) {
        size_t hi = (jac[k] < n ? jac[k] : n - 1);
        size_t lo = jac[k - 1] + 1;
 
        for (size_t idx = hi; idx >= lo && idx < n; --idx) {
            if (!inserted[idx]) {
                order.push_back(idx);
                inserted[idx] = true;
            }
            if (idx == 0) break;
        }
    }
 
    for (size_t i = 0; i < n; ++i) {
        if (!inserted[i])
            order.push_back(i);
    }
 
    return order;
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

    bool oddPairs = (container.size() % 2 != 0);
    int lastDigit = oddPairs ? container[container.size() - 1] : -1;

    if (container.size() % 2 != 0) {
        lastDigit = container.back();
        oddPairs = true;
    }
    
    T largerNums;

    for (size_t i = 0; i < pairs.size(); ++i) {
        largerNums.push_back(pairs[i].second);
    }

    mergeInsertSort(largerNums);

    std::vector<bool> usedPair(pairs.size(), false);
    std::vector<int>  smallForLarger(largerNums.size(), -1);

    for (size_t i = 0; i < largerNums.size(); ++i) {
        for (size_t pi = 0; pi < pairs.size(); ++pi) {
            if (!usedPair[pi] && pairs[pi].second == largerNums[i]) {
                smallForLarger[i] = pairs[pi].first;
                usedPair[pi] = true;
                break;
            }
        }
    }

    T mainChain;
    mainChain.push_back(smallForLarger[0]);
    for (size_t i = 0; i < largerNums.size(); ++i)
        mainChain.push_back(largerNums[i]);

    size_t pendCount = smallForLarger.size() - 1;
    std::vector<size_t> insertOrder = buildInsertionOrder(pendCount);

    for (size_t o = 0; o < insertOrder.size(); ++o) {
        size_t idx  = insertOrder[o] + 1;
        int    val  = smallForLarger[idx];
        typename T::iterator upperBound = mainChain.end();
        for (typename T::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
            if (*it == largerNums[idx]) {
                upperBound = it + 1;
                break;
            }
        }
 
        typename T::iterator pos = std::lower_bound(mainChain.begin(), upperBound, val);
        mainChain.insert(pos, val);
    }
 
    if (oddPairs) {
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), lastDigit);
        mainChain.insert(pos, lastDigit);
    }
 
    container = mainChain;
}

template <typename T>
void PmergeMe::printContainer(std::string str, const T& container) {
    std::cout << str;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::run(int ac, char **av) {
    storeNumsInContainers(ac, av, numsVector);
    storeNumsInContainers(ac, av, numsDeque);

    printContainer("Before: ", numsVector);

    std::clock_t startVector = std::clock();
    mergeInsertSort(numsVector);
    std::clock_t endVector = std::clock();

    std::clock_t startDeque = std::clock();
    mergeInsertSort(numsDeque);
    std::clock_t endDeque = std::clock();

    double vectorTime = static_cast<double>(endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;
    double dequeTime = static_cast<double>(endDeque - startDeque) * 1000000.0 / CLOCKS_PER_SEC;

    printContainer("After: ", numsVector);

    std::cout << "Time to process a range of " << numsVector.size()
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << numsDeque.size()
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
