/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:24:54 by dtanigaw          #+#    #+#             */
/*   Updated: 2022/07/09 18:30:17 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main(void)
{
	Data		toSerialize;
	uintptr_t	serialized;
	Data		*deserialized;

	std::cout << "\033[36mTest #1....\033[0m" << std::endl;
	toSerialize.data = 42;
	std::cout << "original data: " << toSerialize.data << std::endl;
	serialized = serialize(&toSerialize);
	deserialized = deserialize(serialized);
	std::cout << "deserialized data: " << deserialized->data
		<< std::endl << std::endl;


	std::cout << "\033[36mTest #2....\033[0m" << std::endl;
	toSerialize.data = 12345678;
	std::cout << "original data: " << toSerialize.data << std::endl;
	serialized = serialize(&toSerialize);
	deserialized = deserialize(serialized);
	std::cout << "deserialized data: " << deserialized->data
		<< std::endl << std::endl;

	std::cout << "\033[36mTest #3....\033[0m" << std::endl;
	toSerialize.data = 0;
	std::cout << "original data: " << toSerialize.data << std::endl;
	serialized = serialize(&toSerialize);
	deserialized = deserialize(serialized);
	std::cout << "deserialized data: " << deserialized->data
		<< std::endl << std::endl;

	return 0;
}
