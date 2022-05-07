# include <iostream>
# include "PhoneBook.hpp"
# include "Contact.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	Contact		NewContact("Alina");

	PhoneBook.add(NewContact);
	PhoneBook.show();
}
