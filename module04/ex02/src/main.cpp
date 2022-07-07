/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:05:31 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/07 16:05:55 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define COLOR(C, c) C << c << RESET

int main()
// Switch between development/production
{
	Cat a, b;
	Animal *tab[4];
//	Animal	anim = new Animal();

	for (size_t i(0); i < 4; i++)
		i < 2 ? tab[i] = new Cat() : tab[i] = new Dog();

	a.getBrain()->_ideas[0] = "I am A";
	b.getBrain()->_ideas[0] = "I am B";
	std::cout << COLOR(YELLOW, b.getBrain()->_ideas[0]) << std::endl;
	std::cout << COLOR(YELLOW, b.getType()) << std::endl;
	b = a;
	std::cout << COLOR(CYAN, b.getBrain()->_ideas[0]) << std::endl;
	std::cout << COLOR(CYAN, b.getType()) << std::endl;

	for (int i(0); i < 4; i++)
	{
		Animal	*a = tab[i];
		delete a;
	}
}
