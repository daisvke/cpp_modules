/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:48:16 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/02 01:25:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	f(T &src)
{
	std::cout << "Value: " << src << std::endl;
}

template<typename T>
void	iter(T *array, size_t size, void (*f)(T &))
{
	for (size_t i(0); i < size; ++i)
		f(array[i]);
}
