#include "main.hpp"

Contact::Contact()
{
}

void	Contact::show_field(int i) const
{
	std::cout << _fields[i];
}

std::string	Contact::get_field(int i) const
{
	/*
	size_t	size = _fields[i].length();
	char	converted[size + 1];

	strcpy(converted, _fields[i].c_str());
	return ((char *)converted);*/
	return (_fields[i]);
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
