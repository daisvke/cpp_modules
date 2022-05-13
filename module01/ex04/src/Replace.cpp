/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:41:51 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/13 05:09:38 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace()
{
}

bool	Replace::openInFile(std::string fileName)
{
	_inStream.open(fileName);
	if (_inStream)
	{
		_fileName = fileName;
		std::cout << "Input file is set to \'" << fileName << "\'" << std::endl;
		return (true);
	}
	std::cout << "ERROR: Failed to open " << fileName << std::endl;
	return (false);
}

bool	Replace::replace(std::string toReplace, std::string replaceWith)
{
	std::string	res;
	size_t		size = toReplace.length();

	if (toReplace == "")
	{
		std::cerr << "ERROR: Please enter a valid string to replace" << std::endl;
		return (false);
	}
	res.assign((std::istreambuf_iterator<char>(_inStream)),
		(std::istreambuf_iterator<char>()));

	for (int pos=0; pos < res.length(); pos++)
	{
		if (res.compare(pos, size, toReplace) == 0)
		{
			res.erase(pos, size);
			res.insert(pos, replaceWith);
		}
	}
	putToOutFile(res);
	return (true);
}

void	Replace::putToOutFile(std::string fileContent)
{
	std::ofstream	outStream;

	outStream.open(_fileName);
	if (outStream)
	{
		std::cout << "Wrote content into \'" << _fileName << "\'" << std::endl;
		outStream << fileContent;
	}
	else
		std::cerr << "ERROR: Failed to open " << _fileName << std::endl;
}
