#include "inc/DiamondTrap.hpp"

// int main() {
//     DiamondTrap di("Diamond");

//     di.whoAmI();
//     di.attack("enemy");
//     di.takeDamage(5);
//     di.beRepaired(2);
//     di.guardGate();
//     di.highFivesGuys();

//     return 0;
// }

int	main(void)
{
	DiamondTrap	dia("Diamondy");

	dia.attack("SomeTarget");
	dia.takeDamage(30);
	dia.beRepaired(20);
	dia.highFivesGuys();
	dia.guardGate();
	dia.whoAmI();
	return (0);
}
