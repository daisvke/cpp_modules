/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 06:09:34 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/05/20 23:13:16 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i=1; i < argc; ++i)
		{
			while (*argv[i])
			{
				if (isalpha(*argv[i]))
				{
					char	c = toupper(*argv[i]);
					std::cout << c;
				}
				else if (*argv[i] != '"')
					std::cout << *argv[i];
				++argv[i];
			}
		}
	}
	std::cout << std::endl;

	return (0);
}
