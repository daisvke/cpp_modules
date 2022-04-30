#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (int i=0; i < 8; ++i)
		contacts[i] = NULL;
}

void	PhoneBook::add(Contact contact)
{
	int	size;

	size = sizeof(_contacts) / sizeof(*_contacts);
	if (size >= 8)
		_contacts[7] = contact;
	else
		_contact[size] = contact;
}

void	PhoneBook::show() const
{
	for(int i=0; _contacts[i]; ++i)
	{
		cout << _contacts[i].name << endl;
	}
}
