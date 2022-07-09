/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:22:56 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 19:29:37 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	emptyArr;
	std::cout << "empyArr " <<
		(emptyArr.size() == 0 ? "is empty" : "is not empty") << '\n';

	std::cout << std::endl;

	Array<int>	intArr(4);
	std::cout << "Size of intArr..." << intArr.size() << std::endl;

	std::cout << "Value of intArr[0]: " << intArr[0] << std::endl;
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	intArr[3] = 4;
	std::cout << "Size of intArr..." << intArr.size() << std::endl;

	std::cout << std::endl;

	std::cout << "\033[36mTrying below min index...\033[0m" << std::endl;
	try { std::cout << intArr[-42] << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	std::cout << "\033[36mTrying beyond max index...\033[0m" << std::endl;
	try { std::cout << intArr[42] << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	for (size_t i(0); i < intArr.size(); ++i)
	{
		try { std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl; }
		catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	std::cout << std::endl;

	Array<int>	cpyArr;
	std::cout << "Size of cpyArr..." << cpyArr.size() << std::endl;
	std::cout << "\033[36mDeep copying intArr to cpyArr...\033[0m" << std::endl;
	cpyArr = intArr;
	std::cout << "New size of cpyArr..." << cpyArr.size() << std::endl;

	std::cout << "\033[36mChanging value in cpyArr...\033[0m" << std::endl;
	cpyArr[1] = 42;
	for (size_t i(0); i < intArr.size(); ++i)
	{
		try { std::cout << "cpyArr[" << i << "]: " << cpyArr[i] << std::endl; }
		catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	std::cout << std::endl;

	std::cout << "\033[36mChecking if intArray has been modified...\033[0m" << std::endl;
	for (size_t i(0); i < intArr.size(); ++i)
	{
		try { std::cout << "intArr[" << i << "]: " << intArr[i] << std::endl; }
		catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}


	std::cout << std::endl;

	return 0;
}
