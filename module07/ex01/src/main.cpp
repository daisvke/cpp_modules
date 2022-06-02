/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:48:16 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/02 01:25:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main(void)
{
	int			array1[4] = {42, 4242, 424242, 42424242};
	std::string	array2[4] = {"a", "ab", "abc", "abcd"};

	iter(array1, 4, &f);

	std::cout << std::endl;

	iter(array2, 4, &f);

	return 0;
}
