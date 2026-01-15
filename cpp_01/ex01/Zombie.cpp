#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string zombieName) : name(zombieName) {
    std::cout << name << ": Constructor is called" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << ": Destructor is called" << std::endl;
};

// getter
const std::string& Zombie::getName() const { return name; }

 // setter
void Zombie::setName(std::string zombieName) {
    name = zombieName;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


