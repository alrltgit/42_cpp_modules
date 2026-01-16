#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon) : name(newName), weaponA(newWeapon) {};

HumanA::~HumanA() {};

void HumanA::attack() {
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}
