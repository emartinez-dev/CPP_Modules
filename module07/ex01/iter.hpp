/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:24:22 by franmart          #+#    #+#             */
/*   Updated: 2023/09/12 10:08:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, int size, T (*f)(T))
{
	for (int i = 0; i < size; i++)
		array[i] = f(array[i]);
}

template <typename T>
void iter(T *array, int size, void (*f)(T))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void iter(T const &array, int size, void (*f)(T))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T, typename Type>
void iter(T *array, int size, void (*f)(Type))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T, typename Type>
void iter(T const &array, int size, void (*f)(Type))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void print_element(T i)
{
	std::cout << i << ", ";
}

#endif
