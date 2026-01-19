#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie FooStack = Zombie(name);
    FooStack.announce();
}
