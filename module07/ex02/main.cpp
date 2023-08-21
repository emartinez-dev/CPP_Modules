/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:02:54 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 11:18:14 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
void ft_leaks(void)
{
	system("leaks -q array");
}
*/

int main ()
{
	//atexit(ft_leaks);
	std::cout << "Testing creating empty array" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size:" << empty.size() << std::endl;
	
	std::cout << "\nTesting creating array with 5 elements, not modifying values yet" << std::endl;
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ", ";
	
	std::cout << "\n\nTesting the modification of its values" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i + 1;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ", ";

	std::cout << "\n\nTesting the copy constructor\nPrinting array:" << std::endl;
	Array<int> _copy(arr);
	std::cout << "copy size: " << _copy.size() << std::endl;
	for (unsigned int i = 0; i < _copy.size(); i++)
		std::cout << _copy[i] << ", ";
	std::cout << "\n\nTesting the modification of its values" << std::endl;
	for (unsigned int i = 0; i < _copy.size(); i++)
		_copy[i] = 42;
	std::cout << "Printing copy values" << std::endl;
	for (unsigned int i = 0; i < _copy.size(); i++)
		std::cout << _copy[i] << ", ";

	std::cout << "\nPrinting original values" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ", ";

	Array<int> _copy2 = _copy;
	std::cout << "\n\nTesting the assignement constructor\nPrinting array:" << std::endl;
	for (unsigned int i = 0; i < _copy2.size(); i++)
		std::cout << _copy2[i] << ", ";
	std::cout << "\n\nTesting the modification of its values" << std::endl;
	for (unsigned int i = 0; i < _copy2.size(); i++)
		_copy2[i] = 1000001;
	std::cout << "Printing copy values" << std::endl;
	for (unsigned int i = 0; i < _copy2.size(); i++)
		std::cout << _copy2[i] << ", ";

	std::cout << "\nPrinting original values" << std::endl;
	for (unsigned int i = 0; i < _copy.size(); i++)
		std::cout << _copy[i] << ", ";

	std::cout << "\n\nTesting creating array with 3 string elements" << std::endl;
	Array<std::string> str(3);
	for (unsigned int i = 0; i < str.size(); i++)
		str[i] = "42 but as a string";
	for (unsigned int i = 0; i < str.size(); i++)
		std::cout << str[i] << ", ";

	std::cout << "\n\nTesting accesing a " << str.size() << " elements array with " << str.size() + 1 << " index" << std::endl;
	try {
		str[str.size()] = "this should throw an exception";
	}
	catch (const std::exception&) {
		std::cout << "Exception thrown" << std::endl;
	}

	std::cout << "\n\nChecking for leaks:\n";
	return 0;
}
