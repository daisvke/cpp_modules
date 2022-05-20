/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:33:02 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 01:41:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

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