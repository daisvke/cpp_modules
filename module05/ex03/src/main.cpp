/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/22 02:13:14 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	a("A", 132);
	Intern		i;
	Form		*f;

	std::cout << std::endl;

	f = i.makeForm("SC", a.getName());
	std::cout << std::endl;
	std::cout << *f << std::endl;

	f = i.makeForm("PP", a.getName());
	std::cout << std::endl;
	std::cout << *f << std::endl;

	f = i.makeForm("X", a.getName());
	std::cout << std::endl;

	return 0;
}
