/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:05:02 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/18 05:31:09 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

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
