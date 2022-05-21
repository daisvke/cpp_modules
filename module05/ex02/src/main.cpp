/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/21 02:13:20 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	a("A", 144);
	ShrubberyCreationForm	scf("mytarget");
	
	try {a.signForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't sign form: " << e.what() << std::endl;
	}
	
	try {a.executeForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't execute form: " << e.what() << std::endl;
	}
	for (size_t i(0); i < 10; ++i)
		a.incremGrade();
	
	try {a.executeForm(scf);}
	catch (std::exception &e)
	{
		std::cout << "A couldn't execute form: " << e.what() << std::endl;
	}

	return 0;
}
