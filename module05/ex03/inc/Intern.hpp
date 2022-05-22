/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/22 01:41:03 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Form;

class	Intern
{
	public:

	Intern();
	Intern(const Intern &obj);
	Intern	&operator=(const Intern &obj);
	~Intern();
	Form	*makeForm(std::string formName, const std::string target);

	void		signForm(Form &form);
};

#endif

