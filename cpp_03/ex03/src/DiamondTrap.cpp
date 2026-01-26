#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string newName) 
    : FragTrap(name), ScavTrap(name), name(name) {
        std::cout << name << " default constructor called" << std::endl;
    }

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other) {
    std::cout << name << " copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other) {
    if (this != &other) {
        name = other.name;
        // When your derived class (e.g., DiamondTrap) 
        // implements its operator=, it should call 
        // ScavTrap::operator=(other) (and any other base classes' operators). 
        // This ensures ScavTrap's operator= runs, which in turn handles the 
        // ClapTrap attributes.
        FragTrap::operator = (other);
        ScavTrap::operator = (other);
    }
}
