# include <iostream>
# include "PhoneBook.hpp"
# include "Contact.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	Contact		NewContact;

	NewContact.name = "Alina";
	PhoneBook.add(NewContact);
	PhoneBook.show();
}
