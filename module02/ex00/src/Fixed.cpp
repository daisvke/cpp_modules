/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:38:03 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/16 02:10:45 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const Fixed &obj )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return;
}

Fixed &	Fixed::operator=( const Fixed &obj )
{
	std::cout << "Copy assignement operator called" << std::endl;
	_fixedPointNbr = obj.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNbr);
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointNbr = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}
