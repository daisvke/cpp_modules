/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/13 20:15:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love to get extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
		<< std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
		"You don’t put enough! If you did I would not have to ask for it!"
		<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		"I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain( std::string level )
{
	std::string const levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*complaints[])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i=0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			void	(Harl::*complaint)( void ) = complaints[i];
			(this->*complaint)();
		}
	}
}
