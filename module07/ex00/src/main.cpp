/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:46:52 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/06/01 08:06:32 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << std::endl;

	char	ca = 'a', cb = 'b';
	int		ia = 42, ib = 424242;
	float	fa = -2390.0, fb = 263823.232; 
	double	da = -42.0, db = 42424242.42;
	size_t	sa = 2324354523, sb = 2199483682754828;

	std::cout << "Using swap #1..." << std::endl;
	std::cout << "ca: " << ca << ", cb: " << cb << std::endl;
	swap(ca, cb);
	std::cout << "ca:" << ca << "\t\t\tcb: " << cb << std::endl;

	std::cout << std::endl;

	std::cout << "Using swap #2..." << std::endl;
	std::cout << "da: " << da << ", db: " << db << std::endl;
	swap(da, db);
	std::cout << "da:" << da << "\t\tdb: " << db << std::endl;

	std::cout << std::endl;

	std::cout << "Using min #1..." << std::endl;
	std::cout << "ia: " << ia << ", ib: " << ib << std::endl;
	std::cout << "=>" << min(ia, ib) << std::endl;

	std::cout << std::endl;

	std::cout << "Using min #2..." << std::endl;
	std::cout << "ca: " << sa << ", sb: " << sb << std::endl;
	std::cout << "=>" << min(sa, sb) << std::endl;

	std::cout << std::endl;

	std::cout << "Using max #1..." << std::endl;
	std::cout << "ca: " << ca << ", cb: " << cb << std::endl;
	std::cout << "=>" << max(ca, cb) << std::endl;

	std::cout << std::endl;

	std::cout << "Using max #2..." << std::endl;
	std::cout << "fa: " << fa << ", fb: " << fb << std::endl;
	std::cout << "=>" << max(fa, fb) << std::endl;

	return 0;
}
