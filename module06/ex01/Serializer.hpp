/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:04:41 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:10:49 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <cstdint>
# include <iostream>
# include <sys/_types/_uintptr_t.h>
# include "Data.hpp"

class Serializer
{
	private:

	public:
		Serializer();
		~Serializer();
		Serializer(Serializer const &copy);
		Serializer	&operator=(Serializer const &copy);
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
