/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:29 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/22 02:14:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern: Copy constructor called" << std::endl;
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	std::cout << "Intern: Assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
}

Form	*Intern::makeForm(std::string formName, const std::string target)
{
	Form	*form;

	formName == "SC" ? form = new ShrubberyCreationForm(target)
		: (formName == "RR" ? form = new RobotomyRequestForm(target)
		: (formName == "PP" ? form = new PresidentialPardonForm(target)
		: form = 0));

	if (form == 0)
		std::cout << "Error: Unknown form name \'" << formName << "\'" << std::endl;
	else
		std::cout << formName << " generated" << std::endl;

	return form;
}
