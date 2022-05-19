/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:05:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/19 07:39:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animals[4];
	Brain	*brain;
	
	std::cout << std::endl;
	// Init animals array:
	for (int i=0; i < 2; ++i)
		animals[i] = new Cat();
	for (int i=2; i < 4; ++i)
		animals[i] = new Dog();
	
	std::cout << std::endl;

	for (int i=0; i < 4; ++i)
	{
		std::cout << animals[i]->getType() << ": type of animal#" << i << std::endl;

		animals[i]->makeSound();

		brain = animals[i]->getBrain();
		brain->_ideas[0] = "This is my first idea";
		std::cout << animals[i]->getBrain()->_ideas[0] << std::endl;

		std::cout << std::endl;
	}

	brain = animals[1]->getBrain();
	brain->_ideas[30] = "This is my 30th idea";
	std::cout << std::endl;
	*(animals[0]) = *(animals[1]);
	std::cout << animals[0]->getBrain()->_ideas[30] << std::endl;
	std::cout << std::endl;

	// Free array
	for (int i=0; i < 4; ++i)
		delete animals[i];

	return 0;
}
