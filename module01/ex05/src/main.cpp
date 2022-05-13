/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 05:24:47 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/13 19:55:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl harl;

	std::cout << "DUBUG: ";
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO: ";
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING: ";
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR: ";
	harl.complain("ERROR");

	return (0);
}
