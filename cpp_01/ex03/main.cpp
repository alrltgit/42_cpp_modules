#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// What controls copying parameter type:
// - object passed to parameter by value or by reference
// if object is passed to parameter by value - a copy of that object is created
// if object is passed to parameters by reference - no copy!
// Passed by const reference - no copy, read-only!
// Passed by pointer - no copy


int main() { 
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
