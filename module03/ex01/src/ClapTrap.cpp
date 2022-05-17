/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:03:43 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 00:48:23 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		--_energyPoints;
		std::cout << "ClapTrap " << _name << " attacks " << target
			<< " causing " << _attackDamage << " points of damage!"
			<< std::endl;
		std::cout << _name << " loses 1 energy point and has " 
			<< _energyPoints << " energy points left!"
			<< std::endl;
	}
	else
		std::cout << _name << " cannot attack: he is either dead or has no energy points left!"
			<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " is attacked causing "
			<< amount << " points of damage!"
			<< std::endl;
		if (_hitPoints <= 0)
		{
			_hitPoints = 0;
			std::cout << _name << " is dead!" << std::endl;
		}
		else
			std::cout << _name << " has " << _hitPoints << " hit points left!"
				<< std::endl;
	}
	else
		std::cout << _name << " is already dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired causing "
			<< amount << " points of recovery!"
			<< std::endl;
		std::cout << _name << " has " << _hitPoints << " hit points now!"
			<< std::endl;
	}
	else
		std::cout << _name << " cannot be repaired: he has no energy points left!"
			<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
