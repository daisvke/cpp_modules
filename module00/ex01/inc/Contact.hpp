/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:49:12 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:34:40 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include "utils.hpp"

# define FIELD_NBR	5

class	Contact
{
	public:

	Contact();
	void		show_field(int i) const;
	std::string	get_field(int i) const;
	void		add_field(int i, std::string input);
	void		show_field_name(int i) const;
	~Contact();

	class	InvalidTelException: public std::exception
	{
		public:

		InvalidTelException() throw() {}
		virtual const char	*what() const throw() {
			return "Phone number can only contain numbers, +, -, or space!";
		}
		virtual	~InvalidTelException() throw() {}
	};
	
	
	private:

	std::string	_field_names[FIELD_NBR]; 
	std::string	_fields[FIELD_NBR];
};

#endif
