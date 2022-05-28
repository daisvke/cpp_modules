/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/29 00:52:41 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

void	printUsage(void)
{
	std::cerr << std::endl;
	std::cout << "Usage: ./convert [char, int, float, or double]" << std::endl;
	std::cerr << std::endl;
}

void	printNanException(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;

	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string src = argv[1];
		Converter	convert;

		if (src == "nan")
			printNanException();
		convert.detectType(argv[1]);
		try {convert.detectError();}
		catch (std::exception &e)
		{
			std::cerr << "Aborting because of error..." << std::endl;
			std::cerr << std::endl;
			std::cerr << "-> " << e.what() << std::endl;
			printUsage();
			return 1;
		}
		convert.convert(argv[1]);
		convert.printResult(convert, argv[1]);
		return 0;
	}
	printUsage();
	return 1;	
}
