#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string newName) : name(newName), weaponB(NULL) {};

HumanB::~HumanB() {};

void HumanB::attack() {
    std::cout << name << " attacks with their " << weaponB->getType() << std::endl; // weaponB->getType() - arrow because weaponB is a pointer
    // the dot operator is used when we have an object. Bit weaponB is not an object, it's a pointer to one
}

void HumanB::setWeapon(Weapon &newWeaponB) {
    weaponB = &newWeaponB;
}
