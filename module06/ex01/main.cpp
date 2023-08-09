/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:22:53 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 13:49:31 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main (void)
{
	Data		n(42);	
	uintptr_t	ptr;
	Data*		data_ptr;

	std::cout << "Original data pointer: " << &n << std::endl;
	ptr = Serializer::serialize(&n);
	std::cout << "Original data content: " << n.getContent() << std::endl;

	std::cout << "Serialized data pointer: " << ptr << std::endl;
	data_ptr = Serializer::deserialize(ptr);

	std::cout << "Deserialized data pointer: " << data_ptr << std::endl;

	std::cout << "Data after Serializing and deserializing: " \
		<< data_ptr->getContent() << std::endl;

	return 0;
}
