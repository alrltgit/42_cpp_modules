#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int> numsVector;
        std::deque<int> numsDeque;
        std::vector<size_t> jacobsthalSequence(size_t n) const;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        std::vector<size_t> buildInsertionOrder(size_t n) const;

        template <typename T>
        void storeNumsInContainers(int ac, char **av, T& container);

        template <typename T>
        void mergeInsertSort(T& container);

        template <typename T>
        void printContainer(std::string str, const T& container);

        void run(int ac, char **av);
};

#endif
