#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName) 
    : name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap " << name << " constructor is called" << std::endl;
    };

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap " << name << ": Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << ": Destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " 
            << target << " causing " << attackDamage 
            << " points of damage!" << std::endl;;
    } 
    else
        std::cout << "ClapTrap " << name <<  " has no energy or hit points to attack."
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= (int)amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage points, and now is destroyed."
            << std::endl;
    }
    else {
        hitPoints -= (int)amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage points. " 
            << hitPoints << " hit points left." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += (int)amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " has been repaired by " << amount 
        << " hit points and losing 1 energy point. Current hit points: " 
        << hitPoints << std::endl;;
    }
    else {
        energyPoints = 0;
        std::cout << "ClapTrap " << name <<  " has no energy or hit points to repair."
            << std::endl;
    }
}
