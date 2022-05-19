/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:45:38 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 07:14:49 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "Brain.hpp"

class	Brain
{
	public:

	Brain();
	Brain(const Brain &obj);
	Brain	&operator=(const Brain &obj);
	~Brain();

	std::string _ideas[100];
};

#endif
