#include "main.hpp"

PhoneBook::PhoneBook()
{
	_contactNbr = 0;
}

size_t	PhoneBook::get_contact_nbr(void) const
{
	return (_contactNbr);
}

void	PhoneBook::add(void)
{
	Contact		contact;
	std::string	input;
	int			size;

	for (int i=0; i < FIELD_NBR; ++i)
	{
		std::cout << "Enter ";
		contact.show_field_name(i);
		std::cout << ":" << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		contact.add_field(i, input);
	}

	size = get_contact_nbr();
	if (size >= 7)
		_contacts[7] = contact;
	else
		_contacts[size] = contact;
	++_contactNbr;
}

void	PhoneBook::search(void) const
{
	size_t	index;
	size_t	size;
	size_t	max;

	std::cout << "Enter index: " << std::endl;
	std::cin >> index;
	
	size = get_contact_nbr();
	if (size == 0)
		return;
	max =  size - 1 > MAX_CONTACT_NBR ? 0 : size - 1;
	std::cout << std::endl;
	if (index > max)
	{
		std::cout << "Please enter a correct number" << std::endl;
		return ;
	}
	show_contact(index);
}

void	PhoneBook::show_contact(int id) const
{
	size_t	size;

	size = get_contact_nbr();
	for (int i=0; i < FIELD_NBR; ++i)
	{
		_contacts[id].show_field(i);
		std::cout << std::endl;
	}
}

void	PhoneBook::show(void) const
{
	size_t	size;

	size = get_contact_nbr();

	for (int i=0; i < size; ++i)
	{
		for (int j=0; j < FIELD_NBR; ++j)
		{
			_contacts[i].show_field(j);
			std::cout << std::endl;
		}
		std::cout << "==============================" << std::endl;
	}
}

PhoneBook::~PhoneBook()
{
}
