#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:

	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	Weapon&	getWeapon(void) const;
	void	attack(void) const;


	private:

	std::string	_name;
	Weapon		*_weapon;
};
