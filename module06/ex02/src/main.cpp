/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:48:44 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/31 06:05:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
}

int	main(void)
{
	return 0;
}
