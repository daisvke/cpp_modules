/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:40:05 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 20:46:43 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _requiredGradeToSign(_minGrade),
	_requiredGradeToExecute(_minGrade), _isSigned(false)
{
	std::cout << "Form: Default constructor called" << std::endl;
	checkGrade();
}

Form::Form(const std::string name, const size_t requiredGradeToSign,
	const size_t requiredGradeToExecute): _name(name), _isSigned(false),
	_requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "Form: Parameterized constructor called" << std::endl;
	checkGrade();
}

Form::Form(const Form &obj): _name(obj._name), _isSigned(obj._isSigned),
	_requiredGradeToSign(obj._requiredGradeToSign), _requiredGradeToExecute(obj._requiredGradeToExecute)
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
	return _requiredGradeToSign;
}
	
size_t	Form::getRequiredGradeToExecute(void) const
{
	return _requiredGradeToExecute;
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

void	Form::beSigned(const Bureaucrat &obj)
{
	size_t	grade = obj.getGrade();

	if (grade <= _requiredGradeToSign)
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
