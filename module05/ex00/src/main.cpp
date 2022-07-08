/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:42 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 05:50:35 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED		"\033[31m"
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"
#define COLOR(C, c) C << c << RESET

int	main(void)
{
	Bureaucrat	a;

	std::cout << std::endl;
	std::cout << a << std::endl;

	Bureaucrat	b("B", 151);
	Bureaucrat	err("C", -150);
	Bureaucrat	c("C", 150);
	std::cout << c << std::endl;

	std::cout << COLOR(CYAN, "decrementing ") << c.getName() << "..." << std::endl;
	c.decremGrade();
	std::cout << c << std::endl;

	std::cout << COLOR(GREEN, "incrementing ") << c.getName() << "..." << std::endl;
	c.incremGrade();
	std::cout << c << std::endl;

	return 0;
}
