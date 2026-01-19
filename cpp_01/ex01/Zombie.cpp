#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() {
    std::cout << name << ": Destructor is called" << std::endl;
};

const std::string& Zombie::getName() const { return name; }

void Zombie::setName(std::string zombieName) {
    name = zombieName;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


