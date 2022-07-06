/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 21:15:31 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:

	Cat();
	Cat(const Cat &obj);
	Cat	&operator=(const Cat &obj);

	virtual void	makeSound(void) const;
	virtual	~Cat();
};

#endif
