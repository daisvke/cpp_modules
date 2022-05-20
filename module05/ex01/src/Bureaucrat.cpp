/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 20:44:50 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(_minGrade)
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const size_t grade)
	: _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Parameterized constructor called" << std::endl;
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat: Assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

size_t	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::checkGrade(void) const
{
	if (_grade > _minGrade)
		throw (GradeTooLowException());
	else if (_grade < _maxGrade)
		throw (GradeTooHighException());
}

void	Bureaucrat::incremGrade(void)
{
	--_grade;
	checkGrade();
}

void	Bureaucrat::decremGrade(void)
{
	++_grade;
	checkGrade();
}

void	Bureaucrat::signForm(Form &form)
{
	try {form.beSigned(*this);}
	catch (std::string const &errMessage)
	{
		std::cerr << getName() << " couldn't sign " << form.getName()
			<< " form because " << errMessage << std::endl;
	}
	std::cerr << getName() << " signed " << form.getName()
		<< " form " << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &obj)
{
	stream << "Name: " << obj.getName()
	<< ", bureaucrat grade: " << obj.getGrade()
	<< std::endl;

	return stream;
}
