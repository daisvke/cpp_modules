#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
	public:
	
	PhoneBook();
	void	add(Contact contact);
	size_t	get_contact_nbr() const;
	void	show() const;
	~PhoneBook();


	private:
	size_t	_contactNbr;
	Contact _contacts[8];
};

#endif
