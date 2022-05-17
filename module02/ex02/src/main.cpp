/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:30:21 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/17 05:09:39 by dtanigaw         ###   ########.fr       */
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
	a = -30;
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
