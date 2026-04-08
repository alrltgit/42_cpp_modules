#include "easyfind.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(nums, 5);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(nums, 4);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(nums, 1);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(nums, 0);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}