#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is detroyed" << std::endl;
}
