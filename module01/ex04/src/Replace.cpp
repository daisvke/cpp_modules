/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:41:51 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/04 21:28:41 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace()
{
}

bool	Replace::openInFile(const char *fileName)
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
	size_t		replaceWithSize = replaceWith.length();

	if (toReplace == "")
	{
		std::cerr << "ERROR: Please enter a valid string to replace" << std::endl;
		return (false);
	}
	res.assign((std::istreambuf_iterator<char>(_inStream)),
		(std::istreambuf_iterator<char>()));

	size_t	pos = 0;
	while (pos < res.length())
	{
		if (res.compare(pos, size, toReplace) == 0)
		{
			res.erase(pos, size);
			res.insert(pos, replaceWith);
		}
		pos += replaceWithSize;
	}
	if (pos == 0)
	{
		std::cout << "ERROR: Source file is empty!" << std::endl;
		return false;
	}
	putToOutFile(res);
	return (true);
}

void	Replace::putToOutFile(std::string fileContent)
{
	std::ofstream	outStream;
	std::string	fileNameString = _fileName + ".replace";
	const char	*fileName = fileNameString.c_str();

	outStream.open(fileName);
	if (outStream)
	{
		std::cout << "Wrote content into \'" << _fileName << ".replace\'" << std::endl;
		outStream << fileContent;
	}
	else
		std::cerr << "ERROR: Failed to create \'" << _fileName << ".replace\'" << std::endl;
}
