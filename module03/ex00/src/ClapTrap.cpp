/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:03:43 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 16:32:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
		std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name ): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &obj )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &obj )
{
	(void)obj;
	return *this;
}

void	ClapTrap::attack( const std::string &target )
{
	if (_hitPoints > 0 &&_energyPoints > 0)
	{
		_energyPoints = --_energyPoints < 0 ? 0 : _energyPoints;
		std::cout << "ClapTrap " << _name << " attacks " << target
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

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints > 0)
	{
		_hitPoints = _hitPoints - amount < 0 ? 0 : _hitPoints - amount;
		std::cout << "ClapTrap " << _name << " is attacked causing "
			<< amount << " points of damage!"
			<< std::endl;
		if (_hitPoints <= 0)
			std::cout <<
				CT_RED << _name << " is dead!" <<
				CT_WHITE << std::endl;
		else
			std::cout <<
				_name << " has " << _hitPoints << " hit points left!"
				<< std::endl;
	}
	else
		std::cout <<
			CT_RED << _name << " is already dead!"
			<< CT_RED << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired causing "
			<< amount << " points of recovery!"
			<< std::endl;
		std::cout << _name << " has " << _hitPoints << " hit points now!"
			<< std::endl;
		_energyPoints = --_energyPoints < 0 ? 0 : _energyPoints;
	}
	else
		std::cout << CT_RED << _name <<
			" cannot be repaired: he is either dead or has no energy points left!"
			<< CT_WHITE << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
