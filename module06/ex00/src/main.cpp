/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/26 04:19:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Converter	convert;

		convert.detectType(argv[1]);
		convert.detectError();
		return 0;
	}

	return 1;
}
