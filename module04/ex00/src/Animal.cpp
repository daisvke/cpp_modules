/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:05:29 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 00:15:47 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(Animal const &obj)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = obj;
}

void	Animal::makeSound(void) const
{
	std::cout << "The animal made a sound !" << std::endl;
}

const std::string	Animal::getType(void) const
{
	return (_type);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}
