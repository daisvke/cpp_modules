/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/21 22:31:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	a("A", 144);
	ShrubberyCreationForm	scf("mytarget");
	RobotomyRequestForm	rrf(a.getName());

	std::cout << std::endl;
	// ShrubberyCreationForm

	try {a.signForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't sign form: " << e.what() << std::endl;
	}
	
	try {a.executeForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't execute form: " << e.what() << std::endl;
	}
	for (size_t i(0); i < 10; ++i)
		a.incremGrade();
	std::cout << a << std::endl;
	
	try {a.executeForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't execute form: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// RobotomyRequestForm

	try {a.signForm(rrf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't sign form: " << e.what() << std::endl;
	}
	
	try {a.executeForm(rrf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't execute form: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat	b("B", 1);
	try {b.signForm(rrf);}
	catch (std::exception &e)
	{
		std::cout << "B couldn't sign form: " << e.what() << std::endl;
	}
	
	try {b.executeForm(rrf);}
	catch (std::exception &e)
	{
		std::cout << "B couldn't execute form: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {b.executeForm(rrf);}
	catch (std::exception &e)
	{
		std::cout << "B couldn't execute form: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
