#include "Zombie.hpp"

Zombie::void randomChump(std::string name) {
    Zombie *newZ = newZombie(name);
    newZ.announce();
}
