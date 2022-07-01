#include "PhoneBook.hpp"

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

	for (int i(0); i < FIELD_NBR; ++i)
	{
		std::cout << "Enter ";
		contact.show_field_name(i);
		std::cout << ":" << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		contact.add_field(i, input);
	}

	size = get_contact_nbr();
	if (size >= MAX_CONTACT_NBR)
		_contacts[MAX_CONTACT_NBR - 1] = contact;
	else
	{
		_contacts[size] = contact;
		++_contactNbr;
	}
}

void	PhoneBook::search(void) const
{
	size_t	index;
	size_t	size;
	size_t	max;

	show();
	std::cout << "Enter index: " << std::endl;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "Please enter a correct number" << std::endl;
		std::cin.clear();
		return;
	}

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

	std::cout << std::endl;
	size = get_contact_nbr();
	for (int i=0; i < FIELD_NBR; ++i)
	{
		_contacts[id].show_field_name(i);
		std::cout << ": ";
		_contacts[id].show_field(i);
		std::cout << std::endl;
	}
}

std::string	ft_truncate_and_replace(std::string str)
{
	char		new_str[11];
	size_t		len;
	size_t		start;

	len = str.length();
	if (len > 10)
	{
		str[9] = '.';
		str = str.substr(0, 10);
	}
	else if (len < 10)
	{
		for (int i=0; i < 10; ++i)
			new_str[i] = ' ';
		start = 10 - len;
		for (int i=0; str[i]; ++i)
		{
			new_str[start] = str[i];
			++start;
		}
		new_str[10] = 0;
		std::string res(new_str);
		return (res);
	}
	return (str);
}

void	PhoneBook::show(void) const
{
	size_t		size;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	size = get_contact_nbr();

	std::cout << std::string(45, '=') << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << std::string(45, '=') << std::endl;

	for (int i=0; i < size; ++i)
	{
		std::string	index = std::to_string(i);
		index = ft_truncate_and_replace(index);
		firstname = ft_truncate_and_replace(_contacts[i].get_field(FIRSTNAME));
		lastname = ft_truncate_and_replace(_contacts[i].get_field(LASTNAME));
		nickname = ft_truncate_and_replace(_contacts[i].get_field(NICKNAME));

		std::cout << "|" << index << "|" << firstname.c_str() << "|" << lastname.c_str() \
			<< "|" << nickname.c_str() << "|" << std::endl;
		std::cout << std::string(45, '-') << std::endl;
	}
}

PhoneBook::~PhoneBook()
{
}
