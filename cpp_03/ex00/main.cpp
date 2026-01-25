#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap obj("CL4-Df");

    std::cout << std::endl;

    obj.attack("TARGET_1");
    obj.takeDamage(5);
    obj.beRepaired(3);

    std::cout << std::endl;
    return 0;
}
