/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:24:58 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/21 22:33:41 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
	: Form("RobotomyRequestForm", 72, 45), _target(obj.getTarget())
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
	std::cout << "RobotomyRequestForm: Assignement operator called" << std::endl;
	return *this;
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static int	i;

	checkIfExecutable(executor);
	std::cout << "DDDDRRRRRRRRRRRRRRRRRHHHHHHHH" << std::endl;
	if (i % 2 == 0)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "ERROR: The robotomy has failed...!" << std::endl;
	++i;
}
