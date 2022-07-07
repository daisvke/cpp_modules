/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/07 15:58:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(Cat const &obj): Animal(obj)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	_type = obj._type;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat: Assignment constructor called" << std::endl;
	_type = obj._type;
	delete _brain;
	_brain = new Brain(*(obj._brain));
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return _brain;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete _brain;
	_brain = 0;
}
