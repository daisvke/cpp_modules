/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:31:36 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/26 04:08:50 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>

class	Converter
{
	public:

	Converter();
	Converter	&operator=(const Converter &obj);
	Converter(const Converter &obj);
	~Converter();

	void	detectType(std::string src);
	void	detectError(void) const;


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
