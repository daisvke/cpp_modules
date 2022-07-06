/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:37:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 21:15:31 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = obj;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat: Assignment constructor called" << std::endl;
	_type = obj._type;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}
