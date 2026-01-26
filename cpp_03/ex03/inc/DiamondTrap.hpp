#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string name;
    
    public:
        DiamondTrap(std::string newName);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator = (const DiamondTrap& other);
        ~DiamondTrap();

        void whoAmI();
};

#endif
