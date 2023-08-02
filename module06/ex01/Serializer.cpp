/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:05:03 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:30:27 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <sys/_types/_uintptr_t.h>

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(Serializer const &copy)
{
	(void) copy;
}

Serializer	&Serializer::operator=(const Serializer &copy)
{
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

