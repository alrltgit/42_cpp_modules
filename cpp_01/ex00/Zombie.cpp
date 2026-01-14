#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name) {
    name = zombie_name;
};
Zombie::~Zombie() {};

// getter
const std::string& Zombie::get_name( void ) const {
    return name;
}

void Zombie::announce( void ) {
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
