/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:15:03 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:34 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	printUsage(void)
{
	std::cout << std::endl;
	std::cout << "Usage: " << std::endl;
	std::cout << "./replace [file_name] [str_to_replace] [str_to_replace_with]" << std::endl;
}

int	main(int argc, char *argv[])
{
	Replace	replacer;

	if (argc == 4)
	{
		if (replacer.openInFile(argv[1]) == ERROR)
			return (EXIT_FAILURE);
		if (replacer.replace(argv[2], argv[3]) == ERROR)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	std::cout << "ERROR: Unexpected number of arguments" << std::endl;
	printUsage();
	return (EXIT_FAILURE);
}
