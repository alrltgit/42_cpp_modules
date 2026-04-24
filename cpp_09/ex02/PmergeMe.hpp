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
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        template <typename T>
        void storeNumsInContainers(int ac, char **av, T& container);

        void sort(int ac, char **av);
};

#endif
