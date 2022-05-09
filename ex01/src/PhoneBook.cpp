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

	show();
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

	std::cout << std::endl;
	size = get_contact_nbr();
	for (int i=0; i < FIELD_NBR; ++i)
	{
		_contacts[i].show_field_name(i);
		std::cout << ": ";
		_contacts[id].show_field(i);
		std::cout << std::endl;
	}
}

std::string	ft_truncate_and_replace(std::string str)
{
	if (str.length() > 10)
		str[9] = '.';
	return (str.substr(0, 10));
}

void	PhoneBook::show(void) const
{
	size_t		size;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	size = get_contact_nbr();

	std::cout << std::string(45, '=') << std::endl;
	printf("|%10s|%10s|%10s|%10s|\n", \
		"index", "first name", "last name", "nickname");
	std::cout << std::string(45, '=') << std::endl;

	for (int i=0; i < size; ++i)
	{

		firstname = ft_truncate_and_replace(_contacts[i].get_field(FIRSTNAME));
		lastname = ft_truncate_and_replace(_contacts[i].get_field(LASTNAME));
		nickname = _contacts[i].get_field(NICKNAME);
		printf("|%10d|%10s|%10s|%10s|\n", \
			i, firstname.c_str(), lastname.c_str(), nickname.c_str());
		std::cout << std::string(45, '-') << std::endl;
	}
}

PhoneBook::~PhoneBook()
{
}
