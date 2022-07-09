/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 17:00:44 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): _srcType(0), _dot(false), _dotZero(false), _toChar(0)
{
}

Converter	&Converter::operator=(const Converter &obj)
{
	(void)obj;
	return *this;
}

Converter::Converter(const Converter &obj)
{
	_srcType = obj._srcType;
	_dotZero = obj._dotZero;
	_toChar = obj._toChar;
	_toInt = obj._toInt;
	_toFloat = obj._toFloat;
	_toDouble = obj._toDouble;
	*this = obj;
}

Converter::~Converter()
{
}

int	Converter::checkLimits(const std::string &src, int type) const
{
	if (_srcType != _char)
	{
		double	d;

		try { d = atof(src.c_str()); }
		catch (const std::out_of_range& oor) { return _error; }

		d = atof(src.c_str());
		if ((type == _int && d < getMinMax<int>(_min))
			|| (type == _int && d > getMinMax<int>(_max))
			|| (type == _float && d < getMinMax<float>(_min))
			|| (type == _float && d > getMinMax<float>(_max)))
			return _error;
	}
	return _ok;
}

bool	Converter::detectPseudoLiterals(const std::string &src)
{
	std::string	pseudoLiterals[6] = {"-inff", "+inff", "nanf",
									"-inf", "+inf", "nan"};

	for (size_t i(0); i < 6; ++i)
		if (src == pseudoLiterals[i])
			return true;
	return false;
}

void	Converter::detectDotZero(std::string src, size_t pos)
{
	bool	foundNotZero = false;

	for (size_t i(pos); src[i]; ++i)
		if (src[i] != '0' && src[i] != 'f')
			foundNotZero = true;
	if (foundNotZero == false)
		_dotZero = true;
}

void	Converter::detectType(std::string src)
{
	size_t	dotCount = 0, fCount = 0;
	size_t	len = src.length();
	size_t	dotPos;

	for (size_t i(0); src[i]; ++i)
	{
		if (src[i] < ' ')
			_srcType |= _nonPrintable;
		if ((i > 0 && src[i] != '-' && !isdigit(src[i]) && src[i] != '.' && src[i] != 'f')
			|| ((src[i] == 'f' && i != len - 1 && len != 1) || (src[i] == '-' && i != 0))
			|| (src[i] == '.' && ((i == 0 && len != 1) || (i == (len - 1) && len != 1))))
			_srcType |= _noType;
		if (src[i] == '.')
		{
			dotPos = i;
			_dot = true;
			++dotCount;
		}
		if (src[i] == 'f')
			++fCount;
		if (dotCount > 1 || fCount > 1)
			_srcType |= _noType;
	}

	if (len == 1 && !isdigit(src[0]))
		_srcType |= _char;
	else if (dotCount && fCount && src != "-.f")
		_srcType |= _float;
	else if (dotCount && !fCount)
		_srcType |= _double;
	else if ((!dotCount && fCount) || src == "-.f")
		_srcType |= _noType;
	else if (!dotCount && !fCount)
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

	if (toDbl >= ' ' && toDbl <= '~')
		_toChar = static_cast<char>(toDbl);
	else
	{
		_srcType |=_toCharError;
		if (toDbl >= 0 && _toChar  <= 31)
			_toChar |= _nonPrintable;
		else
			_toChar |= _noType;
	}
	_toInt = atoi(src);
	_toFloat = atof(src);
	_toDouble = atof(src);
}

void	Converter::fromFloat(const char *src)
{
	double	toDbl = strtod(src, NULL);

	if (toDbl >= ' ' && toDbl <= '~')
		_toChar = static_cast<char>(toDbl);
	else
	{
		_srcType |=_toCharError;
		if (toDbl >= 0 && _toChar  < 32)
			_toChar |= _nonPrintable;
		else
			_toChar |= _noType;
	}
	_toInt = atoi(src);
	_toFloat = atof(src);
	_toDouble = atof(src);
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

void	Converter::printToCharError(void) const
{
	if (_toChar & _noType)
		std::cout << "impossible";
	else
		std::cout << "Non displayable";
}

void	Converter::printResult(const std::string &src) const
{
	bool	dotZero;

	dotZero = _dot && !_dotZero;
	std::cout << "char:\t\t";
	if (_srcType & _toCharError)
		printToCharError();
	else
		std::cout << "\'" << _toChar << "\'";
	std::cout << std::endl;

	std::cout << "int:\t\t";
	if (checkLimits(src, _int) == _ok)
		std::cout << _toInt;
	else
		std::cout << "impossible";
	std::cout << std::endl;
	
	std::cout << "float:\t\t";
	if (checkLimits(src, _float) == _ok)
		std::cout << _toFloat << (_dot && dotZero ? "" : ".0") << "f";
	else
		std::cout << "impossible";
	std::cout << std::endl;

	std::cout << "double:\t\t";
	if (checkLimits(src, _double) == _ok)
		std::cout << _toDouble << (dotZero ? "" : ".0");
	else
		std::cout << "impossible";
	std::cout << std::endl;
}
