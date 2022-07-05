/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:00:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 18:58:33 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define CT_RED	"\033[1;31m"
# define CT_WHITE	"\033[0m"

class ClapTrap
{
	public:

	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &obj, const std::string name);
	ClapTrap	&operator=(const ClapTrap &obj);
	int			getAttackDamage(void);
	void		attack( const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	~ClapTrap();


	protected:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif
