#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon *weaponB; // can be null
        std::string name;

    public:
        HumanB(std::string newName);
        ~HumanB();

        void setWeapon(Weapon &newWeaponB);
        void attack();
};

#endif
