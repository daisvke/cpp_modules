#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contactNbr = 0;
//	for (int i=0; i < 8; ++i)
//		_contacts[i]._name = 0;
}

size_t	PhoneBook::get_contact_nbr() const
{
	return (_contactNbr);
}

void	PhoneBook::add(Contact contact)
{
	int	size;

	size = get_contact_nbr();
	if (size >= 7)
		_contacts[7] = contact;
	else
		_contacts[size] = contact;
	++_contactNbr;
}

void	PhoneBook::show() const
{
	for(int i=0; i < _contactNbr; ++i)
	{
		std::cout << _contacts[i].show_name() << std::endl;
	}
}

PhoneBook::~PhoneBook()
{
}
