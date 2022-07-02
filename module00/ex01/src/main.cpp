/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:49:48 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/03 00:09:54 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;
	std::string	name;

	ft_print_ascii_art();
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Please enter command:" << std::endl;
		getline(std::cin, command);

		if (std::cin.eof())
			break ;
		else if (command.compare("") == 0)
			std::cout << "Empty command!" << std::endl;
		else if (command.compare("ADD") == 0)
			PhoneBook.add();
		else if (command.compare("SEARCH") == 0)
		{
			if (PhoneBook.get_contact_nbr() == 0)
				std::cout << "PhoneBook is empty!" << std::endl;
			else {
				while (1)
				{
					try { PhoneBook.search(); }
					catch (std::exception &e) { std::cout << e.what() << std::endl; continue; }
					break ;
				}
			}
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
