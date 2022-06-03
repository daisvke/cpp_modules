/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 09:23:38 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span	sp2(200004);

	std::cout << "Trying to read data from an empty array (sp2)..."
		<< std::endl;
	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::cout << "Filling array from sp2 while leaving 4 blocks for the next addition..."
		<< std::endl;
	for (size_t i(0); i < sp2.getMax() - 4; ++i)
		sp2.addNumber(rand());	

	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::vector<int>	vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);

	std::cout << "Filling the remaining 4 blocs from sp2..." << std::endl;
	try {sp2.addNbrByIteratorRange(vect.begin(), vect.end());}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to fill Span object sp3 with an overflowing data..."
		<< std::endl;
	Span				sp3(2);

	try {sp3.addNbrByIteratorRange(vect.begin(), vect.end());}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl;
	std::cout << "Let's see if sp3 remains empty..." << std::endl;
	std::cout << sp3 << std::endl;
	std::cout << std::endl;


	return 0;
}
