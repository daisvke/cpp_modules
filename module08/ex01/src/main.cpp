/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/10 20:35:57 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define CYAN	"\033[36m"
#define RESET	"\033[0m"

int main()
{
	std::cout << "============== from the subject ==============" << std::endl;
	Span	sp = Span(5);
	Span	emptySp;
	std::cout << emptySp << std::endl;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp << std::endl;

	for (int i(0); i < sp.getMax(); ++i)
		std::cout << "Value at " << i << ": " << sp[i] << std::endl;


	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "============== end subject ==============" << std::endl;

	std::cout << CYAN << "Trying to overflaw int..."
		<< RESET << std::endl;
	Span overSp(2);
	overSp.addNumber(-2147483648);
	overSp.addNumber(2147483647);
	std::cout << "Longest span value: " << overSp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span	sp2(200004);
	std::cout << sp2 << std::endl;

	std::cout << CYAN << "Trying to use shortestSpan() on an empty array..."
		<< RESET << std::endl;
	try {sp2.shortestSpan();}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}
	std::cout << CYAN << "Trying to use longestSpan() on an empty array..."
		<< RESET << std::endl;
	try {sp2.longestSpan();}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}

	std::cout << CYAN << "Trying to read data from an empty array (sp2)..."
		<< RESET << std::endl;
	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "Filling array from sp2 while leaving 4 blocks for the next addition..."
		<< RESET << std::endl;
	for (int i(0); i < sp2.getMax() - 4; ++i)
		sp2.addNumber(rand());	

	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::vector<int>	vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);

	std::cout << CYAN << "Filling the remaining 4 blocs from sp2..." << RESET
		<< std::endl;
	try {sp2.addNbrByIteratorRange(vect.begin(), vect.end());}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}

	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "Trying to fill Span object sp3 with an overflowing data..."
		<< RESET << std::endl;
	Span				sp3(2);

	try {sp3.addNbrByIteratorRange(vect.begin(), vect.end());}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}

	std::cout << std::endl;
	std::cout << CYAN << "Let's see if sp3 remains empty..." << RESET << std::endl;
	std::cout << sp3 << std::endl;
	std::cout << std::endl;


	std::cout << CYAN <<
		"===================== Testing lowest/longest ======================"
		<< RESET << std::endl;

	std::cout << CYAN << "Testing lowestSpan()..." << RESET << std::endl;
	std::cout << "Lowest: " << sp2.shortestSpan() << std::endl;

	std::cout << CYAN << "Testing longestSpan()..." << RESET << std::endl;
	std::cout << "Lowest: " << sp2.longestSpan() << std::endl;

	return 0;
}
