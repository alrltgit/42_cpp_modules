#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name) {
    Zombie *newZ = new Zombie(name); // create Zombie object on the heap
    return newZ; // return pointer to caller
};
