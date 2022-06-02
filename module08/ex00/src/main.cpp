/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:03:50 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 01:00:39 by dtanigaw         ###   ########.fr       */
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
	for (auto it(std::begin(vect)); it != std::end(vect); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::cout << "Looking for \'4242'..." << std::endl;
	std::vector<int>::iterator	res = easyfind(vect, 4242);
	std::cout << (res == vect.end() ? "Not found, arrived at end: ": "Found: ");
	std::cout << *res << std::endl;

	std::cout << std::endl;

	std::cout << "Looking for \'42\'..." << std::endl;
	res = easyfind(vect, 42);
	std::cout << (res == vect.end() ? "Not found, arrived at end: ": "Found: ");
	std::cout << *res << std::endl;

	return 0;
}
