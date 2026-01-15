#include "Zombie.hpp"

// Unlike stack memory, heap memory is allocated explicitly by programmers and 
// it won’t be deallocated until it is explicitly freed. To allocate heap memory in C++, 
// use the keyword new followed by the constructor of what you want to allocate. 
// The return value of new operator will be the address of what you just created 
// (which points to somewhere in the heap).

Zombie *newZombie(std::string name) {
    Zombie *newZ = new Zombie(name); // create Zombie object on the heap
    return newZ; // return pointer to caller
};
