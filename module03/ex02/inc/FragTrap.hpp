/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:05:02 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 19:04:26 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

# define CT_RED	"\033[1;31m"
# define CT_WHITE	"\033[0m"

class	FragTrap : public ClapTrap
{
	public:

	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &obj, const std::string name);
	FragTrap	&operator=(const FragTrap &obj);

	void	attack(const std::string &target);
	void	highFivesGuys(void);
	
	~FragTrap();
};

#endif
