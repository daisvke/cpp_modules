/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:00:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 01:43:05 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A"), b("B");
	ScavTrap	s("S"), t("T");

	a.attack("b");
	b.takeDamage(3);
	b.beRepaired(2);

	std::cout << std::endl;

	s.attack("b");
	b.takeDamage(20);

	std::cout << std::endl;
	
	b.attack("s");
	s.guardGate();

	std::cout << std::endl;

	t.attack("s");
	t.takeDamage(200);
	t.beRepaired(100);

	std::cout << std::endl;
	
	s = t;
	s.takeDamage(10);

	return 0;
}
