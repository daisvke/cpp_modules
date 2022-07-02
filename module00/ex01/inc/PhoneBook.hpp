/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:49:02 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 20:21:57 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "Contact.hpp"
# include "utils.hpp"

# define FIRSTNAME	0
# define LASTNAME	1
# define NICKNAME	2

# define MAX_CONTACT_NBR	8

class	PhoneBook
{
	public:
	
	PhoneBook();
	size_t	get_contact_nbr(void) const;
	void	add(void);
	void	search(void) const;
	void	show_contact(int id) const;
	void	show(void) const;
	~PhoneBook();

	class	SearchInvalidInputException: public std::exception
	{
		public:

		SearchInvalidInputException() throw() {}
		virtual const char	*what() const throw() {
			return "Please enter a valid number!";
		}
	};
	class	SearchIncorrectIndexException: public std::exception
	{
		public:

		SearchIncorrectIndexException() throw() {}
		virtual const char	*what() const throw() {
			return "Please enter a correct index!";
		}
	};


	private:

	size_t	_contactNbr;
	Contact _contacts[MAX_CONTACT_NBR];
};

#endif
