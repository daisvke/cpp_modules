/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 23:15:51 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(Dog const &obj)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = obj;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog: Assignment constructor called" << std::endl;
	_type = obj._type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}
