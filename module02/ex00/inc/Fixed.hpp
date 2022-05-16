/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:31:57 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/16 01:36:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:

	Fixed();
	Fixed( const Fixed &obj );
	Fixed		&operator=( const Fixed &obj );
	int			getRawBits( void ) const;
	void		setRawBits( const int raw );
	~Fixed();
	

	private:

	int					_fixedPointNbr;
	static const int	_fractionalBitsNbr = 8;
};

#endif
