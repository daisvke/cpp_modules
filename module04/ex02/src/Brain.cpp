/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:45:52 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 07:24:35 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = obj;
}

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << "Brain: Assignment constructor called" << std::endl;

	for (int i=0; i < 100; ++i)
		_ideas[i] = obj._ideas[i];

	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}
