/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:00:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 16:32:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("A"), b("B");

	for (size_t i(0); i < 11; ++i)
	{
		a.attack("b");
		b.takeDamage(3);
		b.beRepaired(2);
	}

	return 0;
}
