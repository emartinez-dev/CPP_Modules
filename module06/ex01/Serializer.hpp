/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:04:41 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 14:11:32 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/* Why use reinterpet_cast? 
 * Because the uintptr_t is the same size than a normal pointer, and it guarantees that
 * you can cast the value back into its original type, so it's the best for our use
 *
 * Reference: https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
 * */

# include <iostream>
# include "Data.hpp"
# include <stdint.h>

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
