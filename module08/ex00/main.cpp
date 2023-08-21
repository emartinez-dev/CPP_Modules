/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:32:23 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 16:22:30 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 1; i < 11; i++)
	{
		vec.push_back(i * 6);
		lst.push_back(i * 3);
		deq.push_back(i * 5);
	}
	std::cout << "Vector will have number 6 multiplication table: " << std::endl;
	try {
		std::vector<int>::iterator vec_it = easyfind(vec, 60);
		std::cout << "Value found in vector: " << *vec_it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "I will find number 43 in vector: ";
	try {
		std::vector<int>::iterator vec_it = easyfind(vec, 43);
		std::cout << "Value found in vector: " << *vec_it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nList will have number 3 multiplication table: " << std::endl;
	try {
		std::list<int>::iterator lst_it = easyfind(lst, 15);
		std::cout << "Value found in list: " << *lst_it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nDeque will have number 5 multiplication table: " << std::endl;
	try {
		std::deque<int>::iterator deq_it = easyfind(deq, 45);
		std::cout << "Value found in deque: " << *deq_it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

