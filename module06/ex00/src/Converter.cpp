/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/28 22:00:42 by dtanigaw         ###   ########.fr       */
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

void	Converter::fromChar(char *src)
{
	_toChar = src[0];
	_toInt = static_cast<int>(src[0]);
	_toFloat = static_cast<float>(_toInt);
	_toDouble = (double)src[0];
}

void	Converter::fromInt(char *src)
{
	double	toDbl = atoi(src);

	_toChar = (toDbl >= 'a' && toDbl <= 'z') || (toDbl >= 'A' && toDbl <= 'Z') ? static_cast<char>(toDbl) : 0;
	_toInt = atoi(src);
	_toFloat = _toInt;
	_toDouble = _toInt;
}

void	Converter::convert(char *src)
{
	if (_srcType == _char)
		fromChar(src);
	if (_srcType == _int)
		fromInt(src);
}

void	Converter::printResult(Converter res, std::string const &src) const
{
	bool	dotZero;

	dotZero = src.find('.') != std::string::npos
		|| _srcType == _double || _srcType == _float;
	std::cout << "char: ";
	_toChar == 0 ? std::cout << "Non displayable" : std::cout << _toChar;
	std::cout << std::endl;
	std::cout << "int: " << _toInt << std::endl;
	std::cout << "float: " << _toFloat << (dotZero ? "" : ".0") << "f" << std::endl;
	std::cout << "double: " << _toDouble << (dotZero ? "" : ".0") << std::endl;}
