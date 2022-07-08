/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 18:43:51 by dtanigaw         ###   ########.fr       */
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

	std::cout << std::endl;

	Form	*scf;
	scf = i.makeForm("shrubbery creation", a.getName());
	std::cout << std::endl;
	std::cout << *scf;
	std::cout << "\033[36mTarget: " << scf->getTarget() <<
		"\033[0m" << std::endl << std::endl;

	Form	*rrf;
	rrf = i.makeForm("robotomy request", a.getName());
	std::cout << std::endl;
	std::cout << *rrf;
	std::cout << "\033[36mTarget: " << rrf->getTarget() <<
		"\033[0m" << std::endl << std::endl;


	Bureaucrat	b("B", 12);
	Form	*ppf;
	ppf = i.makeForm("presidential pardon", b.getName());
	std::cout << std::endl;
	std::cout << *ppf;
	std::cout << "\033[36mTarget: " << ppf->getTarget() <<
		"\033[0m" << std::endl << std::endl;

	Form	*f;
	f = i.makeForm("X", a.getName());
	std::cout << std::endl;

	delete scf;
	delete rrf;
	delete ppf;

	return 0;
}
