/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 03:00:01 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>

class	Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	~Bureaucrat();

	std::string	getName(void) const;
	size_t		getGrade(void) const;
	void		checkGrade(void) const;
	void		incremGrade(void);
	void		decremGrade(void);

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