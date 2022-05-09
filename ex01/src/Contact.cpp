#include "main.hpp"

Contact::Contact()
{
}

void	Contact::show_field(int i) const
{
	std::cout << _fields[i];
}

void	Contact::add_field(int i, std::string input)
{
	_fields[i] = input;
}

void	Contact::show_field_name(int i) const
{
	std::cout << _field_names[i];
}

Contact::~Contact()
{
}
