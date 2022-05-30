/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:36 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/30 02:37:52 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <errno.h>

class	Converter
{
	public:

	Converter();
	Converter	&operator=(const Converter &obj);
	Converter(const Converter &obj);
	~Converter();

	static bool	detectPseudoLiterals(const std::string &src);

	template<typename T>
	double	getMinMax(int limit) const;
	int		checkLimits(const char *src, int type) const;

	void	detectType(std::string src);
	void	detectDotZero(std::string src, size_t pos);
	void	detectError(const char *src) const;
	void	convert(const char *src);
	void	fromChar(const char *src);
	void	fromInt(const char *src);
	void	fromFloat(const char *src);
	void	printToCharError(void) const;
	void	printResult(Converter res, const char *src) const;

	class	UnhandledTypeException: public std::exception
	{
		public:

		UnhandledTypeException() throw() {}
		virtual const char *what() const throw()
		{
			return "The source string does not correspond to any handled type!";
		}
		virtual ~UnhandledTypeException() throw() {}
	};

	class	NonPrintableException: public std::exception
	{
		public:

		NonPrintableException() throw() {}
		virtual const char *what() const throw()
		{
			return "The source string contains non printable character!";
		}
		virtual ~NonPrintableException() throw() {}
	};


	private:

	int		_srcType;
	bool	_dotZero;
	
	char	_toChar;
	int		_toInt;
	float	_toFloat;
	double	_toDouble;

	enum
	{
		_min = 0,
		_max = 1
	};

	enum
	{
		_error = 0,
		_ok = 1
	};

	enum
	{
		_nonPrintable = 1,
		_noType = 2,
		_toCharError = 4,

		_char = 8,
		_int = 16,
		_float = 32,
		_double = 64,
	};
};

#endif
