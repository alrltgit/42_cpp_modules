#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string newName) : weaponB(NULL), name(newName) {};

HumanB::~HumanB() {};

void HumanB::attack() {
    if (weaponB)
        std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
    else
        std::cout << name << " has no weapon"<< std::endl;
}

void HumanB::setWeapon(Weapon &newWeaponB) {
    weaponB = &newWeaponB;
}
