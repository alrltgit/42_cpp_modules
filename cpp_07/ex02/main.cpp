#include "Array.h"
#include <iostream>

class Person {
    public:
        std::string name;
        int age;

        Person() : name("Default"), age(0) {}
        Person(std::string newName, int newAge) : name(newName), age(newAge) {}
};

int main() {
    std::cout << "========= Simple types =========" << std::endl;
    Array<std::string> arr;
    Array<int> arr1(6);

    for (size_t i = 0; i < arr1.size(); ++i) {
        arr1[i] = i;
    }

    Array<int> arr2 = arr1;

    std::cout << "arr.size(): " << arr.size() << std::endl;
    std::cout << "arr1.size(): " << arr1.size() << std::endl;
    std::cout << "arr2.size(): " << arr1.size() << std::endl;

    // for (size_t i = 0; i < arr1.size(); ++i) {
    //     std::cout << "arr1[" << i << "]: " << arr1[i] << std::endl;
    // }

    // for (size_t i = 0; i < arr2.size(); ++i) {
    //     std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    // }

    std::cout << "arr: " << arr.getArray() << std::endl;
    std::cout << "arr1: " << arr1.getArray() << std::endl;
    std::cout << "arr2: " << arr2.getArray() << std::endl;

    arr1[0] = 20;

    // std::cout << "arr1[0]" << arr1[0] << std::endl;
    // std::cout << "arr2[0]" << arr2[0] << std::endl;

    std::cout << "========= Complex types =========" << std::endl;
    Array<Person> people(3);
    people[0] = Person("Alice", 25);
    people[1] = Person("Bob", 30);
    people[2] = Person("Charlie", 35);

    for (size_t i = 0; i < people.size(); ++i) {
        std::cout << people[i].name << " - " << people[i].age << std::endl;
    }

    return 0;
}
