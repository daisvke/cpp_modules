/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 03:09:36 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;

	std::cout << std::endl;

	try {Bureaucrat	b("B", 151);}
	catch (std::exception &e)
	{
		std::cerr << "Initialized object has a grade that is too high !"
			<< std::endl;
	}

	std::cout << std::endl;

	Bureaucrat	c("C", 150);

	std::cout << std::endl;

	try
	{
		c.decremGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Quitting because of error..." << std::endl;
	}
	std::cout << std::endl;

	c.incremGrade();
	c.incremGrade();
	std::cout << c << std::endl;

	return 0;
}
