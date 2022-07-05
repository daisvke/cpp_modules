/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:33:02 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 19:03:38 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

# define CT_RED	"\033[1;31m"
# define CT_WHITE	"\033[0m"

	class	ScavTrap : public ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &obj);
	ScavTrap	&operator=(const ScavTrap &obj);

	void	attack(const std::string &target);
	void	guardGate(void);
	~ScavTrap();
};

#endif
