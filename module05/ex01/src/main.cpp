/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 05:29:38 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	a;

	std::cout << std::endl;

	std::cout << "Creating B..." << std::endl;
	Bureaucrat	b("B", 151);

	std::cout << "Creating form f..." << std::endl;
	Form f1("f", -1, 15);
	Bureaucrat	c("C", 150);
	std::cout << c << std::endl;

	std::cout << "Decrementing c..." << std::endl;
	c.decremGrade();
	std::cout << "Incrementing c..." << std::endl;
	c.incremGrade();
	std::cout << "Incrementing c..." << std::endl;
	c.incremGrade();
	std::cout << c << std::endl;

	Form	f("F", 148, 147);
	Bureaucrat	d("D", 1);
	std::cout << d << std::endl;
	std::cout << f << std::endl;
	d.signForm(f);
	std::cout << std::endl;

	c.signForm(f);
	std::cout << std::endl;

	return 0;
}
