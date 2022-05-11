#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;

	Zombie = newZombie("Zombie1");
	Zombie->announce();
	delete Zombie;

	randomChump("RandomZombie");

	return (0);
}
