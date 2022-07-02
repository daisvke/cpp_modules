/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:49:38 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 20:49:53 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie
{
	public:
	
	Zombie();
	Zombie(std::string name);
	void	set_name(std::string name);
	void	announce(void);
	~Zombie();

	private:

	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
