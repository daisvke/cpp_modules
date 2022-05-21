#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombies;
	int		N = 5;

	Zombies = zombieHorde(N, "ZombieHordeMember");

	for (int i{0}; i < N; ++i)
		Zombies[i].announce();

	delete [] Zombies;
	Zombies = 0;

	return (0);
}
