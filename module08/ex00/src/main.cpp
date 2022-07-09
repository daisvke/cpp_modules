/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:03:50 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 22:10:09 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
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
	std::vector<int>::iterator	res = easyfind(vect, 4242);
	std::cout << (res == vect.end() ?
			"\033[31mNot found, arrived at end: ": "\033[32mFound: ");
	std::cout << *res << "\033[0m" << std::endl;

	std::cout << std::endl;

	std::cout << "Looking for \'42\'..." << std::endl;
	res = easyfind(vect, 42);
	std::cout << (res == vect.end() ?
			"\033[31mNot found, arrived at end: ": "\033[32mFound: ");
	std::cout << *res << "\033[0m" << std::endl;

	return 0;
}
