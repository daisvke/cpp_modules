#include <iostream>

class	PhoneBook
{
	public:
	
	PhoneBook();
	void	add(Contact contact);
	~PhoneBook();


	private:
	Contact Contacts[8];
};
