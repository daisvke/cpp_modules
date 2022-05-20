/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 20:43:41 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	try {c.decremGrade();}
	catch (std::exception &e)
	{
		std::cerr << "Quitting because of error..." << std::endl;
		std::cerr << "-> " << e.what() << std::endl;
	}
	std::cout << std::endl;

	c.incremGrade();
	c.incremGrade();
	std::cout << c << std::endl;
	std::cout << std::endl;

	Form	f("F", 148, 147);
	Bureaucrat	d("D", 1);
	d.signForm(f);
	std::cout << d << std::endl;
	std::cout << std::endl;

	try {c.signForm(f);}
	catch (std::exception &e)
	{
		std::cerr << "Quitting again because of error..." << std::endl;
		std::cerr << "-> " << e.what() << std::endl;
	}
	std::cout << std::endl;
	c.incremGrade();
	std::cout << c << std::endl;
	c.signForm(f);

	return 0;
}
