/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:48:16 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 18:34:04 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main(void)
{
	int			array1[4] = {42, 4242, 424242, 42424242};
	float		array2[4] = {-42.0, 4242.42, 424242.4242, -42424242.0};
	std::string	array3[4] = {"a", "ab", "abc", "abcd"};

	std::cout << "\033[36mTest #1....\033[0m" << std::endl;
	iter(array1, 4, &f);

	std::cout << std::endl;

	std::cout << "\033[36mTest #2....\033[0m" << std::endl;
	iter(array2, 4, &f);

	std::cout << std::endl;

	std::cout << "\033[36mTest #3....\033[0m" << std::endl;
	iter(array3, 4, &f);

	return 0;
}
