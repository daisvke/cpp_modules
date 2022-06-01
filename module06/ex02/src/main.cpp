/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:48:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/01 04:22:11 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random = rand() % 10;

	if (random <= 3)
		return new A();
	else if (random <= 6)
		return new B();
	else
		return new C();
}

void	identify(Base* p)
{
	std::cout << "pointer: ";
	std::cout << ( dynamic_cast<A *>(p) ? "A" : "");
	std::cout << ( dynamic_cast<B *>(p) ? "B" : "");
	std::cout << ( dynamic_cast<C *>(p) ? "C" : "");
	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "reference: ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch (std::exception &e) {}
	std::cout << std::endl;
}

int	main(void)
{
	Base	*obj;

	std::cout << std::endl;
	std::cout << "Identifying from pointers..." << std::endl;
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
	std::cout << "Identifying from references..." << std::endl;
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
