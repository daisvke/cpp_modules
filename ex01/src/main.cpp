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
		std::cin >> command;
		std::cout << std::endl;
		if (command.compare("ADD") == 0)
			PhoneBook.add();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.search();
		else if (command.compare("END") == 0)
			break ;
	}
	PhoneBook.show();
	return (0);
}
