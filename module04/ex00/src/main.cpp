/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:05:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 21:14:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;

	std::cout << j->getType() << ": type of j(Dog) " << std::endl;
	std::cout << i->getType() << ": type of i(Cat) " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	meta = 0;
	delete j;
	j = 0;
	delete i;
	i = 0;

	std::cout << std::endl;
	std::cout << "============ WRONG ANIMAL ============" << std::endl; 
	std::cout << std::endl;

	const WrongAnimal* Wmeta = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	
	std::cout << std::endl;

	std::cout << c->getType() << ": type of c(WrongCat) " << std::endl;

	std::cout << std::endl;

	c->makeSound();
	Wmeta->makeSound();

	std::cout << std::endl;

	delete Wmeta;
	Wmeta = 0;
	delete c;
	c = 0;

	return 0;
}
