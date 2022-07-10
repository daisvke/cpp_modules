/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:27:00 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/10 20:47:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <list>

#define CYAN "\033[36m"
#define RESET "\033[0m"

int main()
{
	std::list<int> lstack;

	std::cout << CYAN << "Using list..." << RESET << std::endl;
	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);

	std::list<int>::iterator it = lstack.begin();
	std::list<int>::iterator ite = lstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(lstack);

	std::cout << "=======================================" << std::endl;
	std::cout << CYAN << "Using MutantStack..." << RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it2 = mstack.begin();
	MutantStack<int>::iterator ite2 = mstack.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int> s2(mstack);
	return 0;
}
