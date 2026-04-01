#include "Array.h"
#include <iostream>

int main() {
    Array<std::string> arr;
    Array<int> arr1(6);
    const unsigned int arr1Size = arr1.size();
    const unsigned int arrSize = arr.size();

    std::cout << "arrsize: " << arrSize << std::endl;
    std::cout << "arr1size: " << arr1Size << std::endl;

    for (size_t i = 0; i < arr1Size; ++i) {
        arr1[i] = i;
        std::cout << i << ": " << arr1[i] << std::endl;
    }

    return 0;
}
