/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:24:47 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/08 18:11:00 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	virtual	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

	virtual const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;


	private:

	const std::string	_target;
};

#endif
