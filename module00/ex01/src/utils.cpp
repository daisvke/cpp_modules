/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:49:30 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/03 00:06:40 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.hpp"

void	ft_clear_cin()
{
	std::cin.clear();
	std::string ignoreLine;
	std::getline(std::cin, ignoreLine);
}

std::string ft_to_string(size_t val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
