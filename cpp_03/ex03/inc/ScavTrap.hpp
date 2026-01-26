#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

// Private members are inherited, but not accessible in derived classes
class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string newName);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator = (const ScavTrap& other);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};

#endif
