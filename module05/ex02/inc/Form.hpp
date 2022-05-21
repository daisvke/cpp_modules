/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:12:37 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/21 22:26:02 by dtanigaw         ###   ########.fr       */
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
	Form(const std::string name, const size_t requiredGradeToSign,
		const size_t requiredGradeToExecute);
	Form(const Form &obj);
	Form	&operator=(const Form &obj);
	~Form();

	std::string		getName(void) const;
	size_t			getRequiredGradeToSign(void) const;
	size_t			getRequiredGradeToExecute(void) const;
	bool			getStatus(void) const;
	void			checkGrade(void) const;
	void			beSigned(const Bureaucrat &obj);
	virtual void	execute(const Bureaucrat &executor) const = 0;
	void			checkIfExecutable(const Bureaucrat &executor) const;

	class	GradeTooHighException: public std::exception
	{
		public:
	
		GradeTooHighException() throw() {}
		virtual const char	*what() const throw()
		{
			return "Form: The grade is too high!";
		}
		virtual ~GradeTooHighException() throw() {}
	};

	class	GradeTooLowException: public std::exception
	{
		public:
	
		GradeTooLowException() throw() {}
		virtual const char	* what() const throw()
		{
			return "Form: The grade is too low!";
		}
		virtual ~GradeTooLowException() throw() {}
	};

	class	CannotExecuteException: public std::exception
	{
		public:
	
		CannotExecuteException() throw() {}
		virtual const char	* what() const throw()
		{
			return "Form: Cannot execute because either the grade is too low or "
				"the form is unsigned!";
		}
		virtual ~CannotExecuteException() throw() {}
	};


	private:

	const std::string	_name;
	static const size_t	_minGrade = 150;
	static const size_t	_maxGrade = 1;
	bool				_isSigned;
	const size_t		_requiredGradeToSign;
	const size_t		_requiredGradeToExecute;
	
};

std::ostream	&operator<<(std::ostream &stream, const Form &obj);

#endif
