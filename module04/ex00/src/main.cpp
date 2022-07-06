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
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const Animal* j = new Dog();
	
	std::cout << std::endl;

	std::cout << meta->getType() << ": type of meta(Animal) " << std::endl;
	meta->makeSound();
	std::cout << i->getType() << ": type of i(Cat) " << std::endl;
	i->makeSound();
	std::cout << j->getType() << ": type of j(Dog) " << std::endl;
	j->makeSound();

	std::cout << std::endl;

	delete meta;
	meta = 0;
	std::cout << std::endl;
	delete j;
	j = 0;
	std::cout << std::endl;
	delete i;
	i = 0;

	std::cout << std::endl;
	std::cout << "============ WRONG ANIMAL ============" << std::endl; 
	std::cout << std::endl;

	const WrongAnimal* Wmeta = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* c = new WrongCat();
	
	std::cout << std::endl;

	std::cout << c->getType() << ": type of c(WrongCat) " << std::endl;

	std::cout << std::endl;

	Wmeta->makeSound();
	c->makeSound(); // makes Animal's sound and not Cat's sound, since the makeSoundmethod is not virtual

	std::cout << std::endl;

	delete Wmeta;
	Wmeta = 0;
	std::cout << std::endl;
	delete c;
	c = 0;

	return 0;
}
