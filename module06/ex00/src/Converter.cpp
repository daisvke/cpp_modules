/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:18 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/30 05:30:50 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): _srcType(0), _dotZero(false), _toChar(0)
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

template<typename T>
double	Converter::getMinMax(int limit) const
{
	double	res;

	if (limit == _min)
		res = std::numeric_limits<T>::min();
	else if (limit == _max)
		res = std::numeric_limits<T>::max();
	return (res);
}

int	Converter::checkLimits(const std::string &src, int type) const
{
	double	d;
	bool	error = false;

	try { d = std::stod(src, NULL); }
	catch (const std::out_of_range& oor) { return _error; }

	if (_srcType != _char)
	{
		d = std::stod(src, NULL);
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

	for (size_t i=0; i < 6; ++i)
		if (src == pseudoLiterals[i])
			return true;
	return false;
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
	else if (dotCount && !fCount)
		_srcType |= _double;
	else if (!dotCount && fCount)
		_srcType |= _noType;
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
	_toDouble = std::stod(src);
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
	_toDouble = std::stod(src, NULL);
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

void	Converter::printResult(Converter res, const std::string &src) const
{
	bool	dotZero;
	std::cout << "type:   " << _srcType << std::endl;

	dotZero = !_dotZero && (_srcType == _double || _srcType == _float);
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
		std::cout << _toFloat << (dotZero ? "" : ".0") << "f";
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
