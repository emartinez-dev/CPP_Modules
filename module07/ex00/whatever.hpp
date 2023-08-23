/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:04:36 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 08:25:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min (T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max (T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
