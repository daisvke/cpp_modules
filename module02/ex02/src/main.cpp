/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:30:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/17 04:40:03 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: ";
	std::cout << a << std::endl;
	std::cout << "++a: ";
	std::cout << ++a << std::endl;
	std::cout << "a: ";
	std::cout << a << std::endl;
	std::cout << "a++: ";
	std::cout << a++ << std::endl;
	std::cout << "a: ";
	std::cout << a << std::endl;

	Fixed	c( 3 );
	Fixed	res;
	std::cout << "c: ";
	std::cout << c << std::endl;
	a = 30;
	std::cout << "a: ";
	std::cout << a << std::endl;
	std::cout << "a + c: ";
	res = a + c;
	std::cout << res << std::endl;
	std::cout << "a / c (toInt): ";
	std::cout << (a / c).toInt() << std::endl;
	std::cout << "a / c (toFloat): ";
	std::cout << (a / c).toFloat() << std::endl;

	std::cout << "b: ";
	std::cout << b << std::endl;

	std::cout << "max a, b: ";
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
