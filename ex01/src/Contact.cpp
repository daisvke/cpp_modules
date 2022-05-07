#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string name)
{
	_name = name;
}

std::string	Contact::show_name() const
{
	return (_name);
}

Contact::~Contact()
{
}
