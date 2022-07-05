/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:00:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 18:31:46 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A"), b("B");
	ScavTrap	s("S"), t("T");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(3);
	b.beRepaired(2);

	std::cout << "===============================" << std::endl;

	s.attack("B");
	b.takeDamage(20);

	std::cout << std::endl;
	
	b.attack("S");
	s.guardGate();

	std::cout << "===============================" << std::endl;

	t.attack("S");
	t.takeDamage(200);
	t.beRepaired(100);

	std::cout << std::endl;
	
	s = t;
	s.takeDamage(10);

	return 0;
}
