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

		if (command.compare("") == 0)
			std::cout << "Empty command!" << std::endl;
		else if (command.compare("ADD") == 0)
			PhoneBook.add();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.search();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command!" << std::endl;

	}
	return (0);
}
