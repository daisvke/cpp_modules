/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:02:51 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:

	HumanA(std::string name, Weapon &weapon);
	void	setWeapon(Weapon &weapon);
	Weapon&	getWeapon(void) const;
	void	attack(void) const;


	private:

	std::string	_name;
	Weapon		&_weapon;
};
