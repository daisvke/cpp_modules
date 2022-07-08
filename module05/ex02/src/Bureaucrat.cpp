/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 05:34:01 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(_minGrade)
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Parameterized constructor called" << std::endl;
	try {checkGrade();}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	(void)obj;
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

int	Bureaucrat::getGrade(void) const
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
	try {checkGrade();}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		++_grade;
	}
}

void	Bureaucrat::decremGrade(void)
{
	++_grade;
	try {checkGrade();}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		--_grade;
	}
}

void	Bureaucrat::signForm(Form &form)
{
	try {form.beSigned(*this);}
	catch (std::exception &e)
	{
		std::cerr << getName() << " couldn't sign " << form.getName()
			<< " form because " << e.what() << std::endl;
		return ;
	}
	std::cerr << "\033[32m" << getName() << " signed " << form.getName()
		<< " form " << "\033[0m" << std::endl;
}

void	Bureaucrat::executeForm(Form const &form)
{
	try {form.execute(*this);}
	catch (std::exception &e)
	{
		std::cerr << getName() << " couldn't execute " << form.getName()
			<< " form because " << e.what() << std::endl;
		return ;
	}
	std::cerr << getName() << " executed " << form.getName()
		<< " form " << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &obj)
{
	stream << "\033[33m" << "Name: " << obj.getName()
	<< ", bureaucrat grade: " << obj.getGrade()
	<< "\033[0m" << std::endl;

	return stream;
}
