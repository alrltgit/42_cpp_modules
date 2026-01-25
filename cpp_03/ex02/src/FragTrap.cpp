#include "../inc/FragTrap.hpp"
#include "../inc/ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor is called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
    std::cout << "FragTrap " << name << " constructor operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << ": Destructor is called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " is requesting a high five! ✋" << std::endl;
}
