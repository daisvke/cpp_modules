/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:05:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/06 05:10:03 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:

	Animal();
	Animal(const Animal &obj);
	Animal	&operator=(Animal const &rhs);

	virtual void		makeSound(void) const = 0;
	const std::string	getType(void) const;
	virtual ~Animal();


	protected:

	std::string _type;
};

#endif
