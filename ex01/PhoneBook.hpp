#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
	public:
	
	PhoneBook();
	void	add(Contact contact);
	~PhoneBook();


	private:
	Contact _contacts[8];
};

#endif
