/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:53:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/02 22:03:34 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

# define ERROR	0

class Replace
{
	public:

	Replace();
	bool	openInFile(std::string fileName);
	bool	replace(std::string toReplace, std::string replaceWith);
	void	putToOutFile(std::string fileContent);


	private:

	std::string		_fileName;
	std::ifstream		_inStream;
	std::string		_toReplace;
	std::string		_replaceWith;
};

#endif
