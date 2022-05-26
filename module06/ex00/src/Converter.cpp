/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/26 07:41:34 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): _srcType(0)
{
}

Converter	&Converter::operator=(const Converter &obj)
{
	return *this;
}

Converter::Converter(const Converter &obj)
{
	*this = obj;
}

Converter::~Converter()
{
}

void	Converter::detectType(std::string src)
{
	size_t	dotCount = 0, fCount = 0;
	size_t	len = src.length() - 1;

	for (size_t i=0; src[i]; ++i)
	{
		if (src[i] < 32)
			_srcType |= _nonPrintable;
		if (i > 0 && src[i] != '-' && !isdigit(src[i]) && src[i] != '.' && src[i] != 'f')
			_srcType |= _noType;
		if ((src[i] == 'f' && i != len) || (src[i] == '-' && i != 0))
			_srcType |= _noType;
		if (src[i] == '.' && (i == 0 || i == len))
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
	else if (!dotCount && fCount)
		_srcType |= _noType;
	else if (dotCount && !fCount)
		_srcType |= _double;
	else if (!isalpha(src[0]) && !dotCount && !fCount)
		_srcType |= _int;
	else
		_srcType |= _char;
}

void	Converter::detectError(void) const
{
	if (_srcType & _nonPrintable)
		std::cout << "The source string contains non printable character!" << std::endl;
	if (_srcType & _noType)
		std::cout << "The source string does not correspond to any handled type!"
			<< std::endl;//print usage

}

void	Converter::fromChar(std::string src)
{
	_toChar = *src;
	_toInt = atoi(*src);
	_toFloat = atof(*src);
	_toDouble = strtod(*src);
}

void	Converter::convert(std::string src)
{
	if (_srcType == _char)
		fromChar();
}

void	Converter::printResult(Converter res) const
{
	std::cout << "char: " << _toChar << std::endl;
	std::cout << "int: " << _toInt << std::endl;
	std::cout << "float: " << _toFloat << std::endl;
	std::cout << "double: " << _toDouble << std::endl;
}