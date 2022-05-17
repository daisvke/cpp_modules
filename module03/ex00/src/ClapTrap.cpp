/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:03:43 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/17 07:40:52 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string name ): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	this->_initialEnergyPoints = this->_energyPoints;
		std::cout << "Name constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

void	attack( const std::string &target )
{

}

	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );
