/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:26:59 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/10 20:41:39 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class	MutantStack: public std::stack<T>
{
	public:

	MutantStack<T>() {}
	MutantStack<T>(const MutantStack<T> &obj) {
		(void)obj;
		*this = obj;
	}
	virtual	~MutantStack<T>() {};
	MutantStack<T>	&operator=(const MutantStack<T> &obj) {
		(void)obj;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin(void) { return this->c.begin(); }
	iterator	end(void) { return this->c.end(); }
};

#endif
