/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:22:55 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 19:31:10 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template<typename T>
class	Array
{
	public:

	Array<T>(): _size(0), _array(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}

	Array<T>(unsigned int n): _size(n)
	{
		std::cout << "Size constructor called" << std::endl;
		_array = new T[n];
		for (size_t i(0); i < n; ++i)
			_array[i] = 0;
	}

	Array<T>(const Array<T> &obj)
	{
		std::cout << "Copy constructor called" << std::endl;
		*this = obj;
	}

	Array<T>	&operator=(const Array<T> &obj)
	{
		if (this != &obj)
		{
			if (_size > 0)
				delete [] _array;
			_size = obj.size();
			_array = new T[_size];
			for (size_t i(0); i < _size; ++i)
				_array[i] = obj[i];
		}
		return *this;
	}

	T	&operator[](const int i) const
	{
		if (i < 0 || (size_t)i >= _size)
			throw std::overflow_error(
					"\033[31mError: index is out of bounds!\033[0m");
		return _array[i];
	}

	~Array<T>()
	{
		std::cout << "Destructor called" << std::endl;
		if (_size > 0)
			delete [] _array;
	}

	unsigned int	size(void) const
	{
		return _size;
	}


	private:

	unsigned int	_size;
	T				*_array;
};

#endif
