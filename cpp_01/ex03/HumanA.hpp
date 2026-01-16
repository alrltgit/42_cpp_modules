#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        Weapon& weaponA; // reference is exactly the same object
        std::string name;
    
    public:
        HumanA(std::string newName, Weapon& newWeaponA);
        ~HumanA();

        void attack();
};

#endif
