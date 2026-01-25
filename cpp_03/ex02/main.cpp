#include "inc/ScavTrap.hpp"
#include "inc/ClapTrap.hpp"
#include "inc/FragTrap.hpp"

int main(void)
{
    ClapTrap obj0("CL4-Df");
    ScavTrap obj1("AL-34Q");
    FragTrap obj2("SD-32H");

    std::cout << std::endl;

    obj0.attack("TARGET_0");
    obj0.takeDamage(30);
    obj0.beRepaired(20);

    std::cout << std::endl;

    obj1.attack("TARGET_1");
    obj1.takeDamage(30);
    obj1.beRepaired(20);
    obj1.guardGate();

    std::cout << std::endl;
    obj2.attack("TARGET_2");
    obj2.takeDamage(50);
    obj2.beRepaired(10);
    obj2.highFivesGuys();

    std::cout << std::endl;
    return 0;
}
