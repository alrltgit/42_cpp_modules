#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string newName) 
    : ClapTrap(newName + "_clap_trap"), FragTrap(newName), ScavTrap(newName), name(newName) {
        std::cout << "DiamnodTrap " << name << " constructor called" << std::endl;
        hitPoints = FragTrap::hitPoints; // from FragTrap
        energyPoints = ScavTrap::energyPoints; // from ScavTrap
        attackDamage = FragTrap::attackDamage; // from FragTrap
    }

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    std::cout << "DiamnodTrap " << name << " copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other) {
    if (this != &other) {
        name = other.name;
        FragTrap::operator = (other);
        ScavTrap::operator = (other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamnodTrap " << name << ": Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap's name: " << name << ". ClapTrap's name: " << ClapTrap::name << std::endl;
}
