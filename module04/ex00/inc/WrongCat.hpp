/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:29:51 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/05 23:20:19 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

	WrongCat();
	WrongCat(const WrongCat &obj);
	WrongCat	&operator=(const WrongCat &obj);

	void	makeSound(void) const;
	virtual	~WrongCat();
};

#endif
