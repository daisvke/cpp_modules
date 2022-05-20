/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:40:05 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 05:10:10 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _requiredGradeToSign(_minGrade),
	_requiredGradeToExecute_isSigned(_minGrade)
{
	std::cout << "Form: Default constructor called" << std::endl;
}

Form(const std::string name, const size_t requiredGradeToSign,
	const size_t requiredGradeToExecute)
{
	std::cout << "Form: Parameterized constructor called" << std::endl;
	_name = name;
	_isSigned = false;
	_requiredGradeToSign = requiredGradeToSign;
	_requiredGradeToExecute = requiredGradeToExecute;
	checkGrade();
}

Form::Form(const Form &obj)
{
	std::cout << "Form: Copy constructor called" << std::endl;
	*this = obj;
}

Form	&Form::operator=(const Form &obj)
{
	std::cout << "Form: Assignment operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
}

std::string	Form::getName(void) const
{
	return _name;
}

size_t	Form::getRequiredGradeToSign(void) const
{
	return requiredGradeToSign;
}
	
size_t	Form::getRequiredGradeToExecute(void) const
{
	return requiredGradeToExecute;
}

bool	Form::getStatus(void) const
{
	return _isSigned;
}

void	Form::checkGrade(void) const
{
	if (_requiredGradeToSign > _minGrade 
		|| _requiredGradeToExecute > _minGrade )
		throw (GradeTooLowException());
	else if (_requiredGradeToSign < _maxGrade 
		|| _requiredGradeToExecute < _maxGrade )
		throw (GradeTooHighException());
}

void	beSigned(const Bureaucrat &obj)
{
	size_t	grade = Bureaucrat.getGrade();

	if (grade <= _maxGrade)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

std::ostream	&operator<<(std::ostream &stream, const Form &obj)
{
	stream << "Form name: " << obj.getName() << std::endl;
	stream << "Required grade to sign: " << obj.getRequiredGradeToSign()
		<< std::endl;
	stream << "Required grade to execute: " << obj.getRequiredGradeToExecute()
		<< std::endl;
	stream << "Status: "
		<< (obj.getStatus() == true ? "signed" : "not signed")
		<< std::endl;

	return stream;
}
