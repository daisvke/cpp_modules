/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:30:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/04 22:56:31 by dtanigaw         ###   ########.fr       */
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

	std::cout << "--a: ";
	std::cout << --a << std::endl;
	std::cout << "a: ";
	std::cout << a << std::endl;
	std::cout << "a--: ";
	std::cout << a-- << std::endl;
	std::cout << "a: ";
	std::cout << a << std::endl;


	Fixed	c( 3 );
	Fixed	res;
	std::cout << "c: ";
	std::cout << c << std::endl;
	a = -30;
	std::cout << "a: ";
	std::cout << a << std::endl;
	std::cout << "a + c: ";
	res = a + c;
	std::cout << res << std::endl;
	std::cout << "a - c: ";
	res = a - c;
	std::cout << res << std::endl;
	std::cout << "a x c: ";
	res = a * c;
	std::cout << res << std::endl;
	std::cout << "a / c (toInt): ";
	std::cout << (a / c).toInt() << std::endl;
	std::cout << "a / c (toFloat): ";
	std::cout << (a / c).toFloat() << std::endl;

	std::cout << "b: ";
	std::cout << b << std::endl;
	
	Fixed d(5);
	std::cout << "max a, d(Fixed): ";
	std::cout << Fixed::max( a, d ) << std::endl;
	std::cout << "min a, b(Fixed): ";
	std::cout << Fixed::min( a, d ) << std::endl;
	
	Fixed const f(-100);
	Fixed const g(343908.6f);
	std::cout << "max f, g(Fixed const): ";
	std::cout << Fixed::max( f, g ) << std::endl;
	std::cout << "min f, g(Fixed const): ";
	std::cout << Fixed::min( f, g ) << std::endl;

	Fixed	old(a);
	std::cout << "a: ";
	std::cout << a << std::endl;
	if (a > old)
		std::cout << "is sup" << std::endl;
	else
		std::cout << "is not sup" << std::endl;
	a = old;
	if (++a > old)
		std::cout << "is sup" << std::endl;
	else
		std::cout << "is not sup" << std::endl;

	return 0;
}
