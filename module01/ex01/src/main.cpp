/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:49:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 20:49:53 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombies;
	int		N = 5;

	Zombies = zombieHorde(N, "ZombieHordeMember");

	for (int i{0}; i < N; ++i)
		Zombies[i].announce();

	delete [] Zombies;
	Zombies = 0;

	return (0);
}
