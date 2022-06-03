/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:43 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 09:09:36 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

class	Span
{
	public:
	
	Span();
	Span(unsigned int max);
	Span(const Span &obj);
	Span	&operator=(const Span &obj);
	~Span();

	std::vector<int>	getArray(void) const;

	int		getMax(void) const;
	void	addNumber(int nbr);
	void	addNbrByIteratorRange(std::vector<int>::iterator begin,
		std::vector<int>::iterator end);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	class	InvalidArraySizeException: public std::exception
	{
		public:

		InvalidArraySizeException() throw() {}
		virtual const char	*what() const throw()
		{
			return "The array size is incompatible with this method!";
		}
		~InvalidArraySizeException() throw() {}
	};


	private:

	unsigned int		_max;
	std::vector<int>	_array;
};

std::ostream	&operator<<(std::ostream &stream, const Span &obj);

#endif
