/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:25:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 18:11:00 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm: Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj)
	: Form("PresidentialPardonForm", 25, 5), _target(obj._target)
{
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & obj)
{
	(void)obj;
	std::cout << "PresidentialPardonForm: Assignement operator called" << std::endl;
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkIfExecutable(executor);
	std::cout <<
		"\033[35m" << _target << " has been pardoned by Zaphod Beeblebrox" <<
		"\033[0m" << std::endl;
}
