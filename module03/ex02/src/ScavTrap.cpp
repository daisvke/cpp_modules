/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:33:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 19:02:57 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap: Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj, const std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	(void)obj;
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		--_energyPoints;
		std::cout << "ScavTrap " << _name << " attacks " << target
			<< " causing " << _attackDamage << " points of damage!"
			<< std::endl;
		std::cout << _name << " loses 1 energy point and has " 
			<< _energyPoints << " energy points left!"
			<< std::endl;
	}
	else
		std::cout << CT_RED << _name <<
			" cannot attack: he is either dead or has no energy points left!"
			<< CT_WHITE << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}
