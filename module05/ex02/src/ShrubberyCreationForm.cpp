/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:24:56 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 04:55:43 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
	: Form("ShrubberyCreationForm", 145, 137), _target(obj._target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
	(void)obj;
	std::cout << "ShrubberyCreationForm: Assignement operator called" << std::endl;
	return *this;
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	outfile;
	std::string		fileName = _target + "_shrubbery";

	checkIfExecutable(executor);

	outfile.open(fileName.c_str(), std::ios::out);

	size_t	size = 25;
	size_t	space = size / 2;
	
	for (size_t i(1); i < size; ++i)
	{
		if (i % 2 != 0)
		{
			outfile << std::string(space--, ' ');
			outfile << std::string(i, '*') << std::endl;
		}
	}

	size_t	trunk = (size * 10) / 100;
	trunk = trunk % 2 == 0 ? trunk + 1 : trunk;
	space = (size / 2) - (trunk / 2);

	for (size_t i(0); i < trunk; ++i)
	{
		outfile << std::string(space, ' ');
		outfile << std::string(trunk, '=') << std::endl;
	}

	outfile.close();

	std::cout <<
		"\033[35mGenerated " << _target << "_shrubbery file!" <<
		"\033[0m" << std::endl;
}
