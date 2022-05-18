/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:05:04 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 06:02:31 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap: Name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj, const std::string name): ClapTrap(name)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests a positive high five" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		--_energyPoints;
		std::cout << "FragTrap " << _name << " attacks " << target
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

