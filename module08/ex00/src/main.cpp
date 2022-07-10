/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:03:50 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/10 21:17:22 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vect(3, 42);

	vect.push_back(1);

	std::cout << "The container includes:" << std::endl;
	for (std::vector<int>::iterator it(vect.begin());
			it != vect.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::cout << "Looking for \'4242\'..." << std::endl;
	std::vector<int>::iterator	res;
	res = easyfind(vect, 4242);
	if (res == vect.end())
			std::cout << "\033[31mNot found, arrived at end: ";
	else
	{
		std::cout << "\033[32mFound: ";
		std::cout << *res << "\033[0m" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Looking for \'42\'..." << std::endl;
	res = easyfind(vect, 42);
	std::cout << (res == vect.end() ?
			"\033[31mNot found, arrived at end: ": "\033[32mFound: ");
	std::cout << *res << "\033[0m" << std::endl;

	std::list<int>::iterator	res2;
 	int myints[] = {16,2,77,29};
  	std::list<int> myList (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The list includes:" << std::endl;
	for (std::list<int>::iterator it(myList.begin());
			it != myList.end(); ++it)
		std::cout << *it << std::endl;


  	std::cout << "Looking for \'6\'..." << std::endl;
	res2 = easyfind(myList, 6);
	std::cout << (res2 == myList.end() ?
			"\033[31mNot found, arrived at end: ": "\033[32mFound: ");
	std::cout << *res2 << "\033[0m" << std::endl;
  	std::cout << "Looking for \'77\'..." << std::endl;
	res2 = easyfind(myList, 77);
	std::cout << (res2 == myList.end() ?
			"\033[31mNot found, arrived at end: ": "\033[32mFound: ");
	std::cout << *res2 << "\033[0m" << std::endl;

	return 0;
}
