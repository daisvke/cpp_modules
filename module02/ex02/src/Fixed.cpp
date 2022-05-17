/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/17 10:28:03 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNbr(0)
{
}

Fixed::Fixed( const int nbr )
{
	_fixedPointNbr = nbr << _fractionalBits;
}

Fixed::Fixed( const float nbr )
{
	_fixedPointNbr = roundf(nbr * (1 << _fractionalBits));
}

Fixed::Fixed( const Fixed &obj )
{
	*this = obj;
}

Fixed &	Fixed::operator=( const Fixed &obj )
{
	_fixedPointNbr = obj._fixedPointNbr;
	return *this;
}

bool	Fixed::operator>( const Fixed &obj ) const
{
	return (getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<( const Fixed &obj ) const
{
	return (obj > *this);
}

bool	Fixed::operator>=( const Fixed &obj ) const
{
	return (!(*this < obj));
}

bool	Fixed::operator<=( const Fixed &obj ) const
{
	return (!(*this > obj));
}

bool	Fixed::operator==( const Fixed &obj ) const
{
	return (obj.getRawBits() == getRawBits());
}

bool	Fixed::operator!=( const Fixed &obj ) const
{
	return (!(obj == *this));
}

Fixed	Fixed::operator+( const Fixed &obj ) const
{
	Fixed	res;
	res.setRawBits((getRawBits() + obj.getRawBits()));
	return (res);
}


Fixed	Fixed::operator-( const Fixed &obj ) const
{
	Fixed	res;
	res.setRawBits((getRawBits() - obj.getRawBits()));
	return (res);
}

Fixed	Fixed::operator*( const Fixed &obj ) const
{
	Fixed	res(toFloat() * obj.toFloat());
	return (res);
}

Fixed	Fixed::operator/( const Fixed &obj ) const
{
	Fixed	res(toFloat() / obj.toFloat());
	return (res);
}

Fixed	&Fixed::operator++( void )
{
	++_fixedPointNbr;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old(*this);
	++(*this);
	return (old);
}

Fixed	&Fixed::operator--( void )
{
	--_fixedPointNbr;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old(*this);
	--(*this);
	return (old);
}

Fixed	&Fixed::min( Fixed &left, Fixed &right )
{
	return (left < right ? left : right);
}

const Fixed	&Fixed::min( const Fixed &left, const Fixed &right )
{
	return (left < right ? left : right);
}

Fixed	&Fixed::max( Fixed &left, Fixed &right )
{
	return (left > right ? left : right);
}

const Fixed	&Fixed::max( const Fixed &left, const Fixed &right )
{
	return (left > right ? left : right);
}

int	Fixed::getRawBits( void ) const
{
	return (_fixedPointNbr);
}

void	Fixed::setRawBits( const int raw )
{
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
}

std::ostream &operator<<( std::ostream &os, Fixed const &nbr )
{
	os << nbr.toFloat();
	return (os);
}
