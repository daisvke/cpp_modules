/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:45 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 05:43:32 by dtanigaw         ###   ########.fr       */
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

	Span	sp2(200000);

	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	for (size_t i(0); i < sp2.getMax(); ++i)
		sp2.addNumber(rand());	

	std::cout << sp2 << std::endl;
	std::cout << std::endl;
	

	Span	sp3(200002);

	sp3.addNumber(1);
	sp3.addNumber(2);

	try {sp3.addNbrByIteratorRange(sp2.getArray().begin(), sp2.getArray().end());}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl;
	std::cout << sp3 << std::endl;

	return 0;
}
