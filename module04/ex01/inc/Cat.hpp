/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/06 04:43:40 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:

	Cat();
	Cat(const Cat &obj);
	Cat	&operator=(const Cat &obj);
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const;
	virtual	~Cat();


	private:
	
	Brain	*_brain;
};

#endif
