/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:26:59 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/04 07:17:33 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class	MutantStack: public std::stack<T>
{
	public:

	MutantStack<T>() {}
	MutantStack<T>(const MutantStack<T> &obj) {*this = src;}
	~MutantStack<T>() {};
	MutantStack<T>	&operator=(const MutantStack<T> &obj) {
		return *this;
	}
};
