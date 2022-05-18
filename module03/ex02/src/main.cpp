/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:00:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 06:01:57 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	c("C");
	std::cout << std::endl;
	ScavTrap	s("S");
	std::cout << std::endl;
	FragTrap	f("F");

	std::cout << std::endl;

	c.attack("F");
	f.takeDamage(c.getAttackDamage());
	f.beRepaired(3);

	std::cout << std::endl;

	s.attack("C");
	c.takeDamage(s.getAttackDamage());

	std::cout << std::endl;
	
	f.highFivesGuys();
	s.guardGate();

	std::cout << std::endl;

	ClapTrap	x(f, "X");
	s.attack("X");
	x.takeDamage(s.getAttackDamage());
	x.beRepaired(100);

	return 0;
}
