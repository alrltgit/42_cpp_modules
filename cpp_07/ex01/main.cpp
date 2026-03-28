#include "iter.h"

void increment(int& val) {
    ++val;
    std::cout << val << std::endl;
}

void print(const int& val) {
    std::cout << val << std::endl;
}

int main() {
    int list1[5] = {1, 2, 3, 4, 5};
    const int list2[5] = {1, 2, 3, 4, 5};

    std::cout << "========= list1 =========" << std::endl;
    iter(list1, 5, increment);

    std::cout << "========= list2 =========" << std::endl;
    iter(list2, 5, print);
}

