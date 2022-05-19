/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:10:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 21:44:24 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:

	Dog();
	Dog(const Dog &src);
	Dog	&operator=(const Dog &obj);
	Animal &operator=(const Animal &obj);
	
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const;
	~Dog();


	private:
	
	Brain	*_brain;
};

#endif
