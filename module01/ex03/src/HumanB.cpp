#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(0)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

Weapon&	HumanB::getWeapon(void) const
{
	return (*_weapon);
}

void	HumanB::attack(void) const
{
	std::cout << _name << "attacks with their " << _weapon->getType() << std::endl;
}
