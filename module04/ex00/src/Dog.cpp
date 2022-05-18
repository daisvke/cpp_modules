/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:23 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 00:16:06 by dtanigaw         ###   ########.fr       */
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

void	Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}
