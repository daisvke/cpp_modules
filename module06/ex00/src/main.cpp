/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/30 03:14:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

void	printUsage(void)
{
	std::cerr << std::endl;
	std::cerr << "Usage: ./convert [char, int, float, or double]" << std::endl;
}

void	handleError(const char *errMessage)
{
	std::cerr << "Aborting because of error..." << std::endl;
	std::cerr << std::endl;
	std::cerr << "-> " << errMessage << std::endl;
	printUsage();
	exit(EXIT_FAILURE);
}

void	handlePseudoLiterals(const std::string &src)
{
	if (Converter::detectPseudoLiterals(src) == true)
	{
		std::string	pseudoLiteral;

		if (src[1] == 'i')
			pseudoLiteral = src[0] == '-' ? "-inf" : "+inf";
		else
			pseudoLiteral = "nan";
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << pseudoLiteral << "f" << std::endl;
		std::cout << "double: " << pseudoLiteral << std::endl;
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		const std::string &src = argv[1];
		Converter	convert;

		handlePseudoLiterals(src);
		convert.detectType(argv[1]);
		try {convert.detectError();}
		catch (std::exception &e) {handleError(e.what());};
		convert.convert(argv[1]);
		convert.printResult(convert, argv[1]);
		return EXIT_SUCCESS;
	}
	std::cerr << "Invalid number of arguments!" << std::endl;
	printUsage();
	return EXIT_FAILURE;
}
