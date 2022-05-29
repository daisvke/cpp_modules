/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/29 05:49:09 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

#define MIN	0
#define MAX	1

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

template<typename T>
long double	showMinMax(int limit)
{
	long double	res;

	if (limit == MIN)
		res = std::numeric_limits<T>::min();
	std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
	std::cout << std::endl;

	return (res);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		const std::string &src = argv[1];
		Converter	convert;

	std::cout << "int: " << showMinMax<int>(MIN) << std::endl;
		handlePseudoLiterals(src);
		convert.detectType(argv[1]);
		try {convert.detectError(argv[1]);}
		catch (std::exception &e) {handleError(e.what());};
		convert.convert(argv[1]);
		convert.printResult(convert, argv[1]);
		return EXIT_SUCCESS;
	}
	std::cerr << "Invalid number of arguments!" << std::endl;
	printUsage();
	return EXIT_FAILURE;
}
