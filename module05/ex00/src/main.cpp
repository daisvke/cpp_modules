/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/06 06:03:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED		"\033[31m"
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"
#define COLOR(C, c) C << c << RESET

int	main(void)
{
	Bureaucrat	a;

	std::cout << std::endl;
	std::cout << a << std::endl;

	try {Bureaucrat	b("B", 151);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {Bureaucrat	c("C", -150);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	


	Bureaucrat	c("C", 150);
	std::cout << c << std::endl;

	std::cout << COLOR(CYAN, "decrementing ") << c.getName() << "..." << std::endl;
	try
	{
		c.decremGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << COLOR(GREEN, "incrementing ") << c.getName() << "..." << std::endl;
	try
	{
		c.incremGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
