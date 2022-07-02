/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:45:56 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 20:46:14 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;

	Zombie = newZombie("Zombie1");
	Zombie->announce();
	delete Zombie;
	Zombie = 0;

	randomChump("RandomZombie");

	return (0);
}
