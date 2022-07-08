/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:40:05 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 05:31:43 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Form"), _isSigned(false),
	_requiredGradeToSign(_minGrade), _requiredGradeToExecute(_minGrade) 
{
	std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(const std::string name, const int requiredGradeToSign,
	const int requiredGradeToExecute): _name(name), _isSigned(false),
	_requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "Form: Parameterized constructor called" << std::endl;
	try {checkGrade();}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}
}

Form::Form(const Form &obj): _name(obj._name), _isSigned(obj._isSigned),
	_requiredGradeToSign(obj._requiredGradeToSign), _requiredGradeToExecute(obj._requiredGradeToExecute)
{
	std::cout << "Form: Copy constructor called" << std::endl;
	*this = obj;
}

Form	&Form::operator=(const Form &obj)
{
	(void)obj;
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

int	Form::getRequiredGradeToSign(void) const
{
	return _requiredGradeToSign;
}
	
int	Form::getRequiredGradeToExecute(void) const
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
	if (_requiredGradeToSign < _maxGrade 
		|| _requiredGradeToExecute < _maxGrade )
		throw (GradeTooHighException());
}

void	Form::beSigned(const Bureaucrat &obj)
{
	int	grade = obj.getGrade();

	if (grade <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

void	Form::checkIfExecutable(const Bureaucrat &executor) const
{
	if (_isSigned == true && executor.getGrade() <= _requiredGradeToExecute)
		return ;
	else
		throw (CannotExecuteException());
}

std::ostream	&operator<<(std::ostream &stream, const Form &obj)
{
	stream << "\033[36m" <<
		"Form name: " << obj.getName() << std::endl;
	stream << "Required grade to sign: " << obj.getRequiredGradeToSign()
		<< std::endl;
	stream << "Required grade to execute: " << obj.getRequiredGradeToExecute()
		<< std::endl;
	stream << "Status: "
		<< (obj.getStatus() == true ? "signed" : "not signed")
		<< "\033[0m" << std::endl;

	return stream;
}
