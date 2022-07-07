/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/07 18:57:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	a;

	std::cout << std::endl;

	std::cout << "Creating B..." << std::endl;
	try {Bureaucrat	b("B", 151);}
	catch (std::exception &e)
	{
		std::cerr << "-> " << e.what() << std::endl;
	}

	std::cout << "Creating form f..." << std::endl;
	try { Form f("f", -1, 15);}
	catch (std::exception &e)
	{
		std::cerr << "-> " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat	c("C", 150);

	std::cout << "Decrementing c..." << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	try {c.decremGrade();}
	catch (std::exception &e)
	{
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
	std::cout << f << std::endl;
	std::cout << std::endl;

	std::cout << c << std::endl;
	std::cout << f << std::endl;
	std::cout << std::endl;
	std::cout << "C signing form f..." << std::endl;
	try {c.signForm(f);}
	catch (std::exception &e)
	{
		std::cerr << "-> " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Incrementing c..." << std::endl;
	c.incremGrade();
	std::cout << c << std::endl;
	std::cout << f << std::endl;
	std::cout << std::endl;
	try {c.signForm(f);}
	catch (std::exception &e)
	{
		std::cerr << "-> " << e.what() << std::endl;
	}

	return 0;
}
