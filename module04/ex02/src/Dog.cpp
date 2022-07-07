/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/07 16:05:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(Dog const &obj): Animal(obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	_type = obj._type;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog: Assignment constructor called" << std::endl;
	_type = obj._type;
	delete _brain;
	_brain = new Brain(*(obj._brain));
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return _brain;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete _brain;
}
