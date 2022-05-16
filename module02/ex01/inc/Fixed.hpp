/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:31:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/16 04:46:00 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:

	Fixed();
	Fixed( const int nbr);
	Fixed( const float nbr );
	Fixed( const Fixed &obj );
	Fixed		&operator=( const Fixed &obj );
	int			getRawBits( void ) const;
	void		setRawBits( const int raw );
	float		toFloat( void ) const;
	int			toInt( void ) const;
	~Fixed();
	

	private:

	int					_fixedPointNbr;
	static const int	_fractionalBits = 8;
};

std::ostream &operator<<( std::ostream &os, Fixed const &nbr);

#endif
