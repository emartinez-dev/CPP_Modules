/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:03:03 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 10:39:15 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T			*_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(Array const &copy);
		Array	&operator=(Array const &copy);

	unsigned int	size() const;
	T &operator[](unsigned int index);
};

# include "Array.tpp"

#endif
