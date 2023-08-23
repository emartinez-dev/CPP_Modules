/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:27:41 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 08:56:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int double_i(int i)
{
	return (i * 2);
}

std::string uppercase(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int main(void)
{
	int arr [] = {1, 2, 3, 4, 5};
	int size = 5;

	std::cout << "Array before iter: ";
	iter(arr, size, print_element);
	std::cout << "\nCalling double_i function...";
	iter(arr, size, double_i);
	std::cout << "\nArray after iter: ";
	iter(arr, size, print_element);

	std::string str_arr[] = {"hello", "world"};
	int str_size = 2;

	std::cout << "\n\nArray before iter: ";
	iter(str_arr, str_size, print_element);
	std::cout << "\nCalling toupper function...";
	iter(str_arr, str_size, uppercase);
	std::cout << "\nArray after iter: ";
	iter(str_arr, str_size, print_element);
	return (0);
}
