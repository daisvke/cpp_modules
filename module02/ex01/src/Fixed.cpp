/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:38:03 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/16 04:38:28 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const int nbr )
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNbr = nbr << _fractionalBits;
}

Fixed::Fixed( const float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNbr = roundf(nbr * (1 << _fractionalBits));
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
	_fixedPointNbr = obj._fixedPointNbr;
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

int	Fixed::toInt( void ) const
{
	return (_fixedPointNbr >> _fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_fixedPointNbr / (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

std::ostream &operator<<( std::ostream & ostr, Fixed const & instance)
{
	ostr << instance.toFloat();
	return (ostr);
}
