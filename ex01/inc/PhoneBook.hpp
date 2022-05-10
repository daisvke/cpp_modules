#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "Contact.hpp"

# define FIRSTNAME	0
# define LASTNAME	1
# define NICKNAME	2

# define MAX_CONTACT_NBR	2

class	PhoneBook
{
	public:
	
	PhoneBook();
	size_t	get_contact_nbr(void) const;
	void	add(void);
	void	search(void) const;
	void	show_contact(int id) const;
	void	show(void) const;
	~PhoneBook();


	private:

	size_t	_contactNbr;
	Contact _contacts[MAX_CONTACT_NBR];
};

#endif
