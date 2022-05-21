/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/21 01:51:06 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(const std::string name, const size_t grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	~Bureaucrat();

	std::string	getName(void) const;
	size_t		getGrade(void) const;
	void		checkGrade(void) const;
	void		incremGrade(void);
	void		decremGrade(void);
	void		signForm(Form &form);
	void		executeForm(Form const &form);

	class	GradeTooHighException: public std::exception
	{
		public:
	
		GradeTooHighException() throw() {}
		virtual const char	*what() const throw()
		{
			return "The grade is too high!";
		}
		virtual ~GradeTooHighException() throw() {}
	};

	class	GradeTooLowException: public std::exception
	{
		public:
	
		GradeTooLowException() throw() {}
		virtual const char	* what() const throw()
		{
			return "The grade is too low!";
		}
		virtual ~GradeTooLowException() throw() {}
	};


	private:

	const std::string	_name;
	size_t				_grade;
	static const size_t	_minGrade = 150;
	static const size_t	_maxGrade = 1;
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &obj);

#endif
