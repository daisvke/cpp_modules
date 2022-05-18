/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 00:15:57 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat const &obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = obj;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}
