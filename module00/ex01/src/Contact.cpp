#include "Contact.hpp"

Contact::Contact()
{
}

void	Contact::show_field(int i) const
{
	std::cout << _fields[i];
}

std::string	Contact::get_field(int i) const
{
	return (_fields[i]);
}

void	Contact::add_field(int i, std::string input)
{
	if (i == 3)
	{
		while (1)
		{
			for (int i(0); input[i]; ++i)
			{
				if (isalpha(input[i]))
				{
					std::cout << "Phone number shouldn't contain any letters!" << std::endl;
		std::cin.clear();
  		std::string ignoreLine;
  		std::getline(std::cin, ignoreLine);
					break ;
				}
			}
			
		}
	}
	_fields[i] = input;
}

void	Contact::show_field_name(int i) const
{
	std::cout << _field_names[i];
}

Contact::~Contact()
{
}
