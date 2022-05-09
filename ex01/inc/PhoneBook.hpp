#ifndef PHONEBOOK_H
# define PHONEBOOK_H

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
