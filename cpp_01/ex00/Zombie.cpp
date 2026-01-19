#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) {
    name = zombieName;
};

Zombie::~Zombie() {
    std::cout << name << ": Destructor is called" << std::endl;
};

const std::string& Zombie::getName( void ) const { return name; }

void Zombie::announce( void ) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
