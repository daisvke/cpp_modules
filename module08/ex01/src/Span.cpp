/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/03 05:35:57 by dtanigaw         ###   ########.fr       */
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

void	Span::addNbrByIteratorRange(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	std::vector<int>	range(begin, end);

	if (range.size() > (_max - _array.size()))
		throw std::out_of_range("The array does not have enough space left!");
	_array.insert(_array.end(), begin, end);
	std::cout << "addNbrByIteratorRange: The array has been updated!" << std::endl;
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

	return (max - min);
}

int		Span::getMax(void) const
{
	return _max;
}

std::vector<int>	Span::getArray(void) const
{
	return _array;
}

std::ostream	&operator<<(std::ostream &stream, const Span &obj)
{
	std::vector<int>	array = obj.getArray();

	if (array.size())
	{
		int	max = *(std::max_element(array.begin(), array.end()));
		int	min = *(std::min_element(array.begin(), array.end()));

		stream << "Span object info: "
			<< "max size: " << obj.getMax() << ", current size: " << array.size()
			<< ", min: " << min << ", max: " << max;
	}
	else
		stream << "The array is empty!";
	
	return stream;
}
