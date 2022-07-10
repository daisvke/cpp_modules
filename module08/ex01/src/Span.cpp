/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:02:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/10 20:28:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _max(0), _array(0)
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
		throw std::out_of_range(
				"\033[31mThe array has reached its maximum capacity!\033[0m"
				);
	_array.push_back(nbr);
}

void	Span::addNbrByIteratorRange(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	std::vector<int>	range(begin, end);
	
	std::cout << "adding number by iterator range..." << std::endl;
	if (range.size() > (_max - _array.size()))
		throw std::out_of_range(
				"\033[31mThe array does not have enough space left!\033[0m"
				);
	_array.insert(_array.end(), begin, end);
	std::cout << "\033[32mThe array has been updated!\033[0m" << std::endl;
}

size_t	Span::shortestSpan(void) const
{
	std::vector<int>	array = _array;
	size_t	shortest;
	size_t	currentRange;

	if (array.empty() || array.size() <= 1)
		throw InvalidArraySizeException();
	sort(array.begin(), array.end());
	shortest = *(array.begin() + 1) - *(array.begin());
	if (shortest != 0)
	{
		for (size_t i(1); i < array.size() - 1; ++i)
		{
			currentRange = *(array.begin() + i + 1) - *(array.begin() + i);
			if ((currentRange < shortest))
				shortest = currentRange;
			if (shortest == 0)
				return shortest;
		}
	}

	return shortest;
}

size_t	Span::longestSpan(void) const
{
	std::vector<int>	array = _array;

	if (array.empty() || array.size() <= 1)
		throw InvalidArraySizeException();

	int	max = *(std::max_element(array.begin(), array.end()));
	int	min = *(std::min_element(array.begin(), array.end()));
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

const int	&Span::operator[](const int i) const
{
	if (i < 0 || i > (int)_array.size())
		throw std::overflow_error(
				"\033[31mError: index is out of bounds!\033[0m"
				);
	return _array[i];
}

std::ostream	&operator<<(std::ostream &stream, const Span &obj)
{
	std::vector<int>	array = obj.getArray();

	stream << "\033[33m-> Span object info: ";
	if (array.size())
	{
		int	max = *(std::max_element(array.begin(), array.end()));
		int	min = *(std::min_element(array.begin(), array.end()));

			stream << "[max size: " << obj.getMax() << ", current size: " << array.size()
			<< ", min: " << min << ", max: " << max << "]\033[0m" << std::endl;
	}
	else
		stream << "\033[31mThe array is empty!\033[0m";
	
	return stream;
}
