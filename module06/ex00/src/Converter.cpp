/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/26 04:36:00 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): _srcType(0)
{
	std::cout << "Converter: Default constructor called" << std::endl;
}

Converter	&Converter::operator=(const Converter &obj)
{
	std::cout << "Converter: Assignment operator called" << std::endl;
	return *this;
}

Converter::Converter(const Converter &obj)
{
	std::cout << "Converter: Copy constructor called" << std::endl;
	*this = obj;
}

Converter::~Converter()
{
	std::cout << "Converter: Destructor called" << std::endl;
}

void	Converter::detectType(std::string src)
{
	size_t	dotCount = 0, fCount = 0;
	size_t	len = src.length() - 1;

	for (size_t i=0; src[i]; ++i)
	{
		if (src[i] < 32)
			_srcType |= _nonPrintable;
		if (isalpha(src[i]))
			_srcType |= _char;
		if (i > 0 && src[i] != '-' && !isdigit(src[i]) && src[i] != '.' && src[i] != 'f')
			_srcType |= _noType;
		if (src[i] == 'f' && i != len)
			_srcType |= _noType;
		if (src[i] == '.' && (i == 0 || i == len))
			_srcType |= _noType;
		if (src[i] == '-' && i != 0)
			_srcType |= _noType;
		if (src[i] == '.')
			++dotCount;
		if (src[i] == 'f')
			++fCount;
		if (dotCount > 1 || fCount > 1)
			_srcType |=_noType;
	}
	if (dotCount && fCount)
		_srcType |= _float;
	if (!dotCount && fCount)
		_srcType |= _noType;
	if (dotCount && !fCount)
		_srcType |= _double;
}


void	Converter::detectError(void) const
{
	if (_srcType & _nonPrintable)
		std::cout << "The source string contains non printable character!" << std::endl;
	if (_srcType & _noType)
		std::cout << "The source string does not correspond to any handled type!"
			<< std::endl;//print usage

}
