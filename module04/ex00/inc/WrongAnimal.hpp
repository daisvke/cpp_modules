/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:29:49 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 21:12:59 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	WrongAnimal	&operator=(const WrongAnimal &obj);

	void		makeSound(void) const;
	const std::string	getType(void) const;
	virtual ~WrongAnimal();


	protected:

	std::string _type;
};

#endif
