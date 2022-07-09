/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:03:48 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 22:05:48 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int toFind)
{
	typename T::iterator	res = find(
			container.begin(), container.end(), toFind
			);

	if (res == container.end())
		return container.end();
	return res;
}

#endif
