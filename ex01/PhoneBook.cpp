#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (int i=0; i < 8; ++i)
		_contacts[i] = NULL;
}

size_t	ft_get_phonebook_size(Contact phonebook)
{
	size_t	i = 0;

	while (i < 8 && _phonebook[i])
		++i;
	return (i);
}

void	PhoneBook::add(Contact contact)
{
	int	size;

	size = ft_get_phonebook_size(_contacts);
	if (size >= 7)
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
