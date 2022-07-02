/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:02:53 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:

	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	Weapon&	getWeapon(void) const;
	void	attack(void) const;


	private:

	std::string	_name;
	Weapon		*_weapon;
};
