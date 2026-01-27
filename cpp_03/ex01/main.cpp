#include "inc/ScavTrap.hpp"
#include "inc/ClapTrap.hpp"

int main(void)
{
    // ClapTrap obj0("CL4-Df");
    ScavTrap obj1("AL-34Q");

    std::cout << std::endl;

    // obj0.attack("TARGET_1");
    // obj0.takeDamage(30);
    // obj0.beRepaired(20);

    std::cout << std::endl;

    obj1.attack("TARGET_2");
    obj1.takeDamage(50);
    obj1.beRepaired(10);
    obj1.guardGate();

    std::cout << std::endl;
    return 0;
}
