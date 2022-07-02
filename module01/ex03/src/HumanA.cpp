/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:03:01 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon)
{
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

Weapon&	HumanA::getWeapon(void) const
{
	return (_weapon);
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
