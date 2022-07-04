/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:53:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/04 19:01:15 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <stdlib.h>

# define ERROR	0

class Replace
{
	public:

	Replace();
	bool	openInFile(const char *fileName);
	bool	replace(std::string toReplace, std::string replaceWith);
	void	putToOutFile(std::string fileContent);


	private:

	std::string		_fileName;
	std::ifstream		_inStream;
	std::string		_toReplace;
	std::string		_replaceWith;
};

#endif
