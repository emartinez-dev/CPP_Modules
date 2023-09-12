/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:27:41 by franmart          #+#    #+#             */
/*   Updated: 2023/09/12 10:09:40 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int double_i(int i)
{
	return (i * 2);
}

int main(void)
{
	int arr [] = {1, 2, 3, 4, 5};
	int size = 5;

	std::cout << "Array before iter: ";
	iter(arr, size, print_element<int>);
	std::cout << "\nCalling double_i function...";
	iter(arr, size, double_i);
	std::cout << "\nArray after iter: ";
	iter(arr, size, print_element<int>);
	return (0);
}

