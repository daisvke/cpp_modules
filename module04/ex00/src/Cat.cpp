/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 21:15:56 by dtanigaw         ###   ########.fr       */
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

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat: Assignment constructor called" << std::endl;
	_type = obj._type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}
