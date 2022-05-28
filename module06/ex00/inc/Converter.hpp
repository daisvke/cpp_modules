/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:36 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/28 21:33:53 by dtanigaw         ###   ########.fr       */
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
	void	detectError(void) const;
	void	convert(char *src);
	void	fromChar(char *src);
	void	printResult(Converter res, std::string const &src) const;


	private:

	int		_srcType;
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
