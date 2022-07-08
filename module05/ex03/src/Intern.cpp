/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:29 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 18:42:20 by dtanigaw         ###   ########.fr       */
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
	(void)obj;
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

	formName == "shrubbery creation" ? form = new ShrubberyCreationForm(target)
		: (formName == "robotomy request" ? form = new RobotomyRequestForm(target)
		: (formName == "presidential pardon" ? form = new PresidentialPardonForm(target)
		: form = 0));

	if (form == 0)
		std::cout << "\033[31mError: Unknown form name \'" << formName << "\'" <<
			"\033[0m" << std::endl;
	else
		std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;

	return form;
}
