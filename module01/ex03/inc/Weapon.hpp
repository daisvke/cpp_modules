/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:02:54 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

# include <iostream>

class	Weapon
{
	public:

	Weapon(std::string type);
	const std::string	&getType(void) const;
	void			setType(std::string type);


	private:

	std::string	_type;
};

#endif
