/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:22:56 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/02 05:39:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	intArr(4);
	
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	intArr[3] = 4;

	std::cout << std::endl;

	std::cout << "Trying below min index..." << std::endl;
	try { std::cout << intArr[-42] << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	std::cout << "Trying beyond max index..." << std::endl;
	try { std::cout << intArr[42] << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;

	for (size_t i(0); i < intArr.size(); ++i)
	{
		try { std::cout << intArr[i] << std::endl; }
		catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	std::cout << std::endl;

	return 0;
}
