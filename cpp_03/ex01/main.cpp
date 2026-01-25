#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    // ClapTrap obj1("CL4-Df");
    ScavTrap obj("AL-34Q");

    std::cout << std::endl;

    obj.attack("TARGET_1");
    obj.takeDamage(30);
    obj.beRepaired(20);
    obj.guardGate();
    std::cout << std::endl;
    obj.attack("TARGET_2");
    obj.takeDamage(50);
    obj.beRepaired(10);
    obj.guardGate();

    std::cout << std::endl;
    return 0;
}
