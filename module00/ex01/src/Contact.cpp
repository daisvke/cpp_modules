/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:49:58 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:34:40 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_field_names[0] = "first name";
	_field_names[1] = "last name";
	_field_names[2] = "nickname";
	_field_names[3] = "phone number";
	_field_names[4] = "darkest secret";
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
		for (int i(0); input[i]; ++i)
		{
			if (!isdigit(input[i]) && input[i] != '-' && input[i] != ' ' && input[i] != '+')
			{
				ft_clear_cin();
				throw(InvalidTelException());
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
