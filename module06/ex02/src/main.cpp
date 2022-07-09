/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:48:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 18:03:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random = rand() % 10;

	std::cout << "Generated: ";
	if (random <= 3)
	{
		std::cout << "\033[31mA\033[0m" << std::endl; 
		return new A();
	}
	else if (random <= 6)
	{
		std::cout << "\033[32mB\033[0m" << std::endl; 
		return new B();
	}
	else
	{
		std::cout << "\033[33mC\033[0m" << std::endl; 
		return new C();
	}
}

void	identify(Base* p)
{
	std::cout << "Pointer: ";
	std::cout << ( dynamic_cast<A *>(p) ? "\033[31mA\033[0m" : "");
	std::cout << ( dynamic_cast<B *>(p) ? "\033[32mB\033[0m" : "");
	std::cout << ( dynamic_cast<C *>(p) ? "\033[33mC\033[0m" : "");
	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Reference: ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "\033[31mA\033[0m";
		(void)a;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "\033[32mB\033[0m";
		(void)b;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "\033[33mC\033[0m";
		(void)c;
	}
	catch (std::exception &e) {}
	std::cout << std::endl;
}

int	main(void)
{
	Base	*obj;

	std::cout << std::endl;
	std::cout << "\033[36mIdentifying from pointers...\033[0m" << std::endl;
	std::cout << std::endl;

	obj = generate();
	identify(obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(obj);
	delete obj;
	obj = 0;

	std::cout << std::endl;
	std::cout << "\033[36mIdentifying from references...\033[0m" << std::endl;
	std::cout << std::endl;

	obj = generate();
	identify(*obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(*obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(*obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(*obj);
	delete obj;
	obj = 0;

	obj = generate();
	identify(*obj);
	delete obj;
	obj = 0;

	return 0;
}
