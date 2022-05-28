/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/29 00:57:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): _srcType(0), _dotZero(false)
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

void	Converter::detectDotZero(std::string src, size_t pos)
{
	bool	foundNotZero = false;

	for (size_t i=pos; src[i]; ++i)
		if (src[i] != '0' && src[i] != 'f')
			foundNotZero = true;
	if (foundNotZero == false)
		_dotZero = true;
}

void	Converter::detectType(std::string src)
{
	size_t	dotCount = 0, fCount = 0;
	size_t	len = src.length() - 1;
	size_t	dotPos;

	for (size_t i=0; src[i]; ++i)
	{
		if (src[i] < ' ')
			_srcType |= _nonPrintable;
		if (i > 0 && src[i] != '-' && !isdigit(src[i]) && src[i] != '.' && src[i] != 'f')
			_srcType |= _noType;
		if ((src[i] == 'f' && i != len) || (src[i] == '-' && i != 0))
			_srcType |= _noType;
		if (src[i] == '.' && (i == 0 || i == len))
			_srcType |= _noType;
		if (src[i] == '.')
		{
			dotPos = i;
			++dotCount;
		}
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
	if (dotCount == 1)
		detectDotZero(src, ++dotPos);
}

void	Converter::detectError(void) const
{
	if (_srcType & _nonPrintable)
		throw NonPrintableException();
	if (_srcType & _noType)
		throw UnhandledTypeException();
}

void	Converter::fromChar(const char *src)
{
	_toChar = src[0];
	_toInt = static_cast<int>(src[0]);
	_toFloat = static_cast<float>(_toInt);
	_toDouble = (double)src[0];
}

void	Converter::fromInt(const char *src)
{
	double	toDbl = strtod(src, NULL);

	_toChar = (toDbl >= ' ' && toDbl <= '~') ? static_cast<char>(toDbl) : 0;
	_toInt = atoi(src);
	_toFloat = _toInt;
	_toDouble = _toInt;
}

void	Converter::fromFloat(const char *src)
{
	double	toDbl = strtod(src, NULL);

	_toChar = (toDbl >= 'a' && toDbl <= 'z') || (toDbl >= 'A' && toDbl <= 'Z') ? static_cast<char>(toDbl) : 0;
	_toInt = atoi(src);
	_toFloat = atof(src);
	_toDouble = _toFloat;
}

void	Converter::convert(const char *src)
{
	if (_srcType == _char)
		fromChar(src);
	if (_srcType == _int)
		fromInt(src);
	if (_srcType == _float)
		fromFloat(src);
	if (_srcType == _double)
		fromFloat(src);
}

void	Converter::printResult(Converter res, std::string const &src) const
{
	bool	dotZero;

	dotZero = !_dotZero && (_srcType == _double || _srcType == _float);
	std::cout << "char: ";
	_toChar == 0 ? std::cout << "Non displayable" : std::cout << "\'" << _toChar << "\'";
	std::cout << std::endl;
	std::cout << "int: " << _toInt << std::endl;
	std::cout << "float: " << _toFloat << (dotZero ? "" : ".0") << "f" << std::endl;
	std::cout << "double: " << _toDouble << (dotZero ? "" : ".0") << std::endl;
}
