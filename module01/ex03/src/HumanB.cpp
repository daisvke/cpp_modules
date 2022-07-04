/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:03:03 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/04 23:33:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(0)
{
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}

Weapon&	HumanB::getWeapon(void) const
{
	return (*_weapon);
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
