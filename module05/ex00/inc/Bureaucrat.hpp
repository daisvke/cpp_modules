/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/06 06:01:56 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>

class	Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	~Bureaucrat();

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		checkGrade(void) const;
	void		incremGrade(void);
	void		decremGrade(void);

	class	GradeTooHighException: public std::exception
	{
		public:
	
		GradeTooHighException() throw() {}
		virtual const char	*what() const throw()
		{
			return "\033[31mThe grade is too high!\033[0m";
		}
		virtual ~GradeTooHighException() throw() {}
	};

	class	GradeTooLowException: public std::exception
	{
		public:
	
		GradeTooLowException() throw() {}
		virtual const char	* what() const throw()
		{
			return "\033[31mThe grade is too low!\033[0m";
		}
		virtual ~GradeTooLowException() throw() {}
	};


	private:

	const std::string	_name;
	int					_grade;
	static const int	_minGrade = 150;
	static const int	_maxGrade = 1;
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &obj);

#endif
