/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:36 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/29 00:47:32 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <cmath>

class	Converter
{
	public:

	Converter();
	Converter	&operator=(const Converter &obj);
	Converter(const Converter &obj);
	~Converter();

	void	detectType(std::string src);
	void	detectDotZero(std::string src, size_t pos);
	void	detectError(void) const;
	void	convert(const char *src);
	void	fromChar(const char *src);
	void	fromInt(const char *src);
	void	fromFloat(const char *src);
	void	printResult(Converter res, std::string const &src) const;

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
		_char = 1,
		_int = 2,
		_float = 4,
		_double = 8,

		_nonPrintable = 16,
		_noType = 32,
	};
};

#endif
