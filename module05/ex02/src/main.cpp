/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 05:11:10 by dtanigaw         ###   ########.fr       */
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

	std::cout << std::endl;
	// ShrubberyCreationForm
	std::cout << "=============SHRUBERRY==============" << std::endl;

	std::cout << a << std::endl;
	std::cout << scf << std::endl;

	a.signForm(scf);
	a.executeForm(scf);

	for (size_t i(0); i < 10; ++i)
	{
		std::cout << "Incrementing A...\t" << i + 1 << std::endl;
		a.incremGrade();
	}
	std::cout << a << std::endl;
	std::cout << scf << std::endl;
	
	a.executeForm(scf);
	std::cout << std::endl;


	// RobotomyRequestForm
	std::cout << "=============ROBOTOMY==============" << std::endl;

	RobotomyRequestForm		rrf(a.getName());

	std::cout << a << std::endl;
	std::cout << rrf << std::endl;

	a.signForm(rrf);
	a.executeForm(rrf);
	std::cout << std::endl;

	Bureaucrat	b("B", 1);
	std::cout << b << std::endl;

	b.signForm(rrf);
	b.executeForm(rrf);
	b.executeForm(rrf);
	std::cout << std::endl;


	// PresendentialPardonForm
	std::cout << "=============PRESIDENTIAL==============" << std::endl;

	Bureaucrat	c("C", 6);
	PresidentialPardonForm	ppf(c.getName());

	std::cout << c << std::endl;
	std::cout << ppf << std::endl;

	c.executeForm(ppf);
	c.signForm(ppf);
	c.executeForm(ppf);
	
	std::cout << "Incrementing C..." << std::endl;
	c.incremGrade();
	std::cout << c << std::endl;

	c.executeForm(ppf);
	std::cout << std::endl;

	return 0;
}
