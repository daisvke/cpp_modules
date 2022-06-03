/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 03:28:37 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _max(0)
{
}

Span::Span(unsigned int max): _max(max), _array(0)
{
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span	&Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		_max = obj._max;
		_array = obj._array;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int nbr)
{
	if (_array.size() == _max)
		throw std::out_of_range("The array has reached its maximum capacity!");
	_array.push_back(nbr);
}

int	Span::shortestSpan(void) const
{
	std::vector<int>	array = _array;
	int	shortest;
	int	currentRange;

	if (array.size() <= 1)
		throw InvalidArraySizeException();
	if (std::is_sorted(array.begin(), array.end()) == false)
		sort(array.begin(), array.end());
	shortest = *(array.begin() + 1) - *(array.begin());
	if (shortest != 0)
	{
		for (size_t i(1); i < array.size() - 1; ++i)
		{
			currentRange = *(array.begin() + i + 1) - *(array.begin() + i);
			if ((currentRange < shortest))
				shortest = currentRange;
		}
	}

	return shortest;
}

int	Span::longestSpan(void) const
{
	std::vector<int>	array = _array;
	int	max = *(std::max_element(array.begin(), array.end()));
	int	min = *(std::min_element(array.begin(), array.end()));

	if (array.size() <= 1)
		throw InvalidArraySizeException();

	return  (max - min);
}
