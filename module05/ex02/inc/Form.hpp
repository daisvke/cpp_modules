/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:12:37 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 03:44:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:

	Form();
	Form(const std::string name, const int requiredGradeToSign,
		const int requiredGradeToExecute);
	Form(const Form &obj);
	Form	&operator=(const Form &obj);
	~Form();

	std::string	getName(void) const;
	int		getRequiredGradeToSign(void) const;
	int		getRequiredGradeToExecute(void) const;
	bool	getStatus(void) const;
	void	checkGrade(void) const;
	void	beSigned(const Bureaucrat &obj);
	virtual void	execute(const Bureaucrat &executor) const = 0;
	void			checkIfExecutable(const Bureaucrat &executor) const;

	class	GradeTooHighException: public std::exception
	{
		public:
	
		GradeTooHighException() throw() {}
		virtual const char	*what() const throw()
		{
			return "\033[31mForm: The grade is too high!\033[0m";
		}
		virtual ~GradeTooHighException() throw() {}
	};

	class	GradeTooLowException: public std::exception
	{
		public:
	
		GradeTooLowException() throw() {}
		virtual const char	* what() const throw()
		{
			return "\033[31mForm: The grade is too low!\033[0m";
		}
		virtual ~GradeTooLowException() throw() {}
	};

	class	CannotExecuteException: public std::exception
	{
		public:
	
		CannotExecuteException() throw() {}
		virtual const char	* what() const throw()
		{
			return "\033[31mForm: Cannot execute because either the grade is too low or "
				"the form is unsigned!\033[0m";
		}
		virtual ~CannotExecuteException() throw() {}
	};


	private:

	const std::string	_name;
	static const int	_minGrade = 150;
	static const int	_maxGrade = 1;
	bool				_isSigned;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExecute;
	
};

std::ostream	&operator<<(std::ostream &stream, const Form &obj);

#endif
